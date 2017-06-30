# State of Linux on the MacBook Pro 2016

The following document provides an overview about Linux support for the Apple
MacBook Pro 2016 line.

The MacBook Pro 2016 shares surprisingly many components with the Retina
MacBook (e.g. keyboard and touchpad controller, Wi-Fi and bluetooth chipsets,
...), so figuring out how things work on one device should benefit both device
families.

As the Apple MacBook Pro 2017 are nearly identical to their 2016 counterparts,
everything noted should apply to them as well, although that's still untested.
Feedback regarding that is welcome.

The checks if hardware works below were done with multiple Linux distributions.
To state the obvious: The newer the kernel the better. If in doubt which kernel
to use, the latest significant improvements are part of Linux 4.11.

If you don't know what the model identifier for your MacBook Pro is (as that
identifier is on several occasions below), check
https://support.apple.com/en-us/HT201300


## Contribution

If you want to contribute to get Linux running smoothly on the MacBook Pro
2016, report all findings how to get devices working as pull requests! All help
is appreciated.


## Current status

| Device  | Status |
| ------- | ------ |
| [Audio input & output](#audio-input--output) | :x: not working |
| [Battery](#battery) | :heavy_check_mark: working |
| [Bluetooth](#bluetooth) | :x: not working |
| [FaceTime HD camera](#facetime-hd-camera) | :heavy_check_mark: working |
| [Graphics card](#intel) (Intel) | :heavy_check_mark: working |
| [Graphics card](#amd) (AMD) | :heavy_check_mark: working |
| [Keyboard & Touchpad](#keyboard--touchpad) | :heavy_check_mark: working with out-of-tree driver |
| [NVMe](#nvme) (internal SSD) | :heavy_check_mark: working |
| [Screen](#screen) | :heavy_check_mark: working |
| [Suspend & Hibernation](#suspend--hibernation) | :x: not working |
| [System Management Controller](#system-management-controller) | :heavy_check_mark: working for MacBookPro13,1<br />:x: working partially for MacBookPro13,2 & MacBookPro13,3 |
| [Thunderbolt](#thunderbolt) | untested, patch available |
| [Touch Bar](#touch-bar) | :heavy_check_mark: basic functionality with out-of-tree driver |
| [Touch ID](#touch-id) | :x: not working |
| [USB](#usb) | :heavy_check_mark: working |
| [Wi-Fi](#wi-fi) | :heavy_check_mark: working for MacBookPro13,1<br />:x: not working for MacBookPro13,2 & MacBookPro13,3 |


## Booting

To boot Linux version earlier than 4.10 properly, it's necessary to set
`intremap=nosid` as kernel boot parameter. From 4.10 onwards that's not
necessary anymore.


## Audio input & output

Not working, neither the internal speakers/microphone nor the headphone jack.

What's working is audio via HDMI or any USB-connected audio device, so that can
act as a workaround until internal audio is working.

See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=195671
* https://bugzilla.kernel.org/show_bug.cgi?id=110561


## Battery

Working fine, including the interface to get current capacity, temperature,
etc.

Battery life is still suboptimal, because power saving modes for several
devices, like display (panel self refresh), SSD or the Thunderbolt
controllers, aren't working yet. You can expected a battery life of less
than 4 hours.

## Bluetooth

Not working.

Uses the same ACPI ID `BCM2E7C` as the Retina MacBooks, so certainly it's also
a `BCM43241`.


See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=110901
* https://www.spinics.net/lists/linux-bluetooth/msg66167.html


## FaceTime HD camera

In the MacBookPro13,1 (without Touch Bar) the FaceTime HD camera is connected
via PCIe, like in previous MacBook Pro's. It's working with the
[`bcwc_pcie`](https://github.com/patjak/bcwc_pcie/wiki) driver.

The models with Touch Bar have the FaceTime HD camera connected through the
iBridge device via USB. They are exposed as regular USB video devices and work
after applying the following quirk using the `uvcvideo` driver:
```
echo "options uvcvideo quirks=0x100" > /etc/modprobe.d/uvcvideo.conf
```


## Graphics card

### Intel

Graphical output using the Intel GPU is working out of the box on the
MacBookPro 13,1 and 13,2, without dedicated AMD GPU. For the MacBookPro 13,3
with dedicated AMD GPU, only the AMD is enabled when booting a OS which isn't
macOS, so you have to follow the instructions in the following link to enable
the integrated Intel GPU, if you want to use it:
https://github.com/Dunedan/mbp-2016-linux/issues/6#issuecomment-286168538

Connecting external displays via USB-C-to-DisplayPort cables works fine,
including connections with daisy-chaining/MST. An actual tested and working
setup includes concurrent output on the internal display and two external
displays daisy-chained together with Full HD each.

### AMD

Working since Linux 4.9.

See also:

* https://gist.github.com/roadrunner2/1289542a748d9a104e7baec6a92f9cd7#gistcomment-1981040
* https://lists.freedesktop.org/archives/amd-gfx/2016-November/003673.html


## Keyboard & Touchpad

Basic keyboard and touchpad functionality is working with the out-of-tree
driver developed for the Retina Macbook
(https://github.com/cb22/macbook12-spi-driver).

The Esc and function keys are part of the Touch Bar, so follow the
instructions for the [Touch Bar](#touch-bar) to get it working.

Beside the actual keyboard the power button and the lid close event work out of
the box.

See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=99891
* https://bugzilla.kernel.org/show_bug.cgi?id=108331


## NVMe

Works out of the box with Linux 4.11 and above.

The MacBookPro 13,1 or MacBookPro 13,2 on earlier versions of Linux need an
out-of-tree patch
(http://lists.infradead.org/pipermail/linux-nvme/2016-May/004618.html) or the
following workaround:
```
modprobe nvme
echo 106b 2003 > /sys/bus/pci/drivers/nvme/new_id
```

The MacBookPro13,1, MacBookPro13,2, MacBookPro14,1 and MacBookPro14,2
occasionally can't properly initialize the NVMe controller after Linux took
over from the boot manager, resulting in timeout messages and the inability to
access the SSD and therefore the failure to boot. The only workaround known so
far is to reboot until the problem isn't triggered.

The SSDs used in the MacBook Pros don't seem to support APST. As it's currently
unknown how power saving works for those SSDs it's likely they consume way more
power than they need to, therefore reducing the battery life.

See also:
* https://unix.stackexchange.com/questions/283154/accessing-the-nvme-flash-drive-of-the-april-2016-macbook-12-a1534
* https://bugzilla.kernel.org/show_bug.cgi?id=99891


## Screen

Works out of the box.

Adjustable screen brightness only works out of the box for the models without
additional AMD Radeon GPU (MacBookPro13,1 and MacBookPro13,2). For the
MacBookPro13,3 with additional AMD Radeon GPU the following patch is necessary:
https://bugzilla.kernel.org/show_bug.cgi?id=105051#c32

The only oddity noticed so far, is that the EDID data for the 13" model
describes two modes: `2560x1600` and `2880x1800`. Xorg probes and sets the
correct resolution of `2560x1600`.
For a detailed look into the EDID data, check out
[macbook13,2/card0-eDP-1.edid](macbook13,2/card0-eDP-1.edid).


## Suspend & Hibernation

Putting the MacBook Pro into suspend mode works, but it doesn't wake up again.
@roadrunner2 did some work in this area. You'll find some details about it in
https://github.com/cb22/macbook12-spi-driver/pull/30#issuecomment-306316034


## System Management Controller

The System Management Controller is responsible for interactions with sensors,
fans.

Fans, temperature and voltage sensors work out of the box using the `applesmc`
kernel module, while the ambient light sensors only work in the MacBookPro13,1.

An accelerometer doesn't seem to be available at all.


## Thunderbolt

Untested, but probably working with the following patch:
https://gist.github.com/l1k/3ffbd63ac337fa85530f6db3e9ee77e9

See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=189731


## Touch Bar

Not working out of the box, but thanks to @roadrunner2 basic functionality
is working using the driver you can find at:
https://github.com/roadrunner2/macbook12-spi-driver/blob/touchbar-driver-hid-driver/appletb.c

Missing is as of now just the advanced functionality with custom graphics Apple
offers in macOS.


## Touch ID

Not working.


## USB

Works out of the box.


## Wi-Fi

The MacBookPro13,1 comes with a `Broadcom Limited BCM4350 802.11ac Wireless
Network Adapter` which works fine out of the box using the `brcmfmac` driver
(ensure you got the matching firmware package installed).

The MacBookPro13,2 and MacBookPro13,3 come with a `Broadcom Limited BCM43602
802.11ac Wireless LAN SoC (rev 02)` which is also supported by `brcmfmac`, but
has several issues, which could simply be firmware related:
* Only 2.4Ghz APs are shown
* Connecting to an AP barely works or fails directly

See also:

* https://bugzilla.kernel.org/show_bug.cgi?id=193121
* https://bugzilla.kernel.org/show_bug.cgi?id=100201
* https://bugzilla.kernel.org/show_bug.cgi?id=103201


## Misc

### History of improvements per kernel version

#### 4.9

* Working AMD graphics of the MacBookPro13,3 (which is the only model with both
  Intel and AMD graphics).

#### 4.10

* `intremap=nosid` as kernel boot parameter not necessary anymore, although
  it's unclear why.

#### 4.11

* The NVMe controller in the MacBookPro13,1 and MacBookPro13,2 is now working
  out of the box (the one in the MacBookPreo13,3 was already working before).
* When booting with kernel modesetting (KMS) the screen isn't scrambled during
  boot anymore.

### iBridge

The models with Touch Bar feature an additional USB device, called *iBridge*
(*Bus 001 Device 002: ID 05ac:8600 Apple, Inc.*). It's probably the interface
to the chip running iOS and providing access to the FaceTime HD camera (that's
why `uvcvideo` detects it), the Touch Bar (that's why it's shown as an
additonal input device in the Xorg log) and the Touch ID button.

`usb-devices` shows that *iBridge* exposes four interfaces:
```
T:  Bus=01 Lev=01 Prnt=01 Port=02 Cnt=01 Dev#=  4 Spd=480 MxCh= 0
D:  Ver= 2.00 Cls=ef(misc ) Sub=02 Prot=01 MxPS=64 #Cfgs=  3
P:  Vendor=05ac ProdID=8600 Rev=01.01
S:  Manufacturer=Apple Inc.
S:  Product=iBridge
S:  SerialNumber=nomac?123456
C:  #Ifs= 4 Cfg#= 1 Atr=e0 MxPwr=0mA
I:  If#= 0 Alt= 0 #EPs= 0 Cls=0e(video) Sub=01 Prot=00 Driver=(none)
I:  If#= 1 Alt= 0 #EPs= 1 Cls=0e(video) Sub=02 Prot=00 Driver=(none)
I:  If#= 2 Alt= 0 #EPs= 1 Cls=03(HID  ) Sub=01 Prot=01 Driver=usbhid
I:  If#= 3 Alt= 0 #EPs= 1 Cls=03(HID  ) Sub=00 Prot=01 Driver=usbhid
```

The two `video` interfaces could be the FaceTime HD camera and the Touch Bar,
while the two `HID` interfaces could be the Touch Bar and the Touch ID button.

Booting macOS as a VM interestingly leads to the following changed output of
`usb-devices`:
```
T:  Bus=01 Lev=01 Prnt=01 Port=02 Cnt=01 Dev#=  2 Spd=480 MxCh= 0
D:  Ver= 2.00 Cls=ef(misc ) Sub=02 Prot=01 MxPS=64 #Cfgs=  3
P:  Vendor=05ac ProdID=8600 Rev=01.01
S:  Manufacturer=Apple Inc.
S:  Product=iBridge
S:  SerialNumber=nomac?123456
C:  #Ifs= 8 Cfg#= 2 Atr=e0 MxPwr=0mA
I:  If#= 0 Alt= 0 #EPs= 0 Cls=0e(video) Sub=01 Prot=00 Driver=uvcvideo
I:  If#= 1 Alt= 0 #EPs= 1 Cls=0e(video) Sub=02 Prot=00 Driver=(none)
I:  If#= 2 Alt= 0 #EPs= 1 Cls=03(HID  ) Sub=00 Prot=01 Driver=usbhid
I:  If#= 3 Alt= 0 #EPs= 2 Cls=10() Sub=00 Prot=00 Driver=(none)
I:  If#= 4 Alt= 0 #EPs= 0 Cls=02(commc) Sub=0d Prot=00 Driver=(none)
I:  If#= 5 Alt= 0 #EPs= 0 Cls=0a(data ) Sub=00 Prot=01 Driver=(none)
I:  If#= 6 Alt= 0 #EPs= 1 Cls=03(HID  ) Sub=00 Prot=01 Driver=usbhid
I:  If#= 7 Alt= 0 #EPs= 2 Cls=ff(vend.) Sub=f9 Prot=11 Driver=(none)
```

Seems like macOS somehow initalizes some additional capabilities of the
*iBridge*.

### Disable auto-boot

Apple introduced an "auto-boot" feature with the MacBook Pro 2016 causing the
notebook to be switched on, whenever the screen lid is opened. By modifying a
NVRAM variable this can be (luckily) disabled again.

How to do that from macOS as well as enabling the startup chime again is
documented e.g. at
http://www.idownloadblog.com/2016/10/31/how-to-stop-the-new-macbook-pro-from-automatically-turning-on-when-the-lid-is-open/

To disable auto boot from within Linux, ensure that `efivarfs` is mounted and
run:
```
printf "\x07\x00\x00\x00\x00" > /sys/firmware/efi/efivars/AutoBoot-7c436110-ab2a-4bbb-a880-fe41995c9f82
```

If you get "No space left on device" errors, it's probably because of
`dump-type0-*`-variables written by the Linux kernel taking up all space.
Removing them solves the problem:
```
for i in $(find /sys/firmware/efi/efivars/ -name 'dump-type0*'); do chattr -i $i; rm $i; done
```

With disabled auto boot the MacBook Pro will show the battery percentage for a
brief second as an image on the screen whenever you open the lid or plug in the
power cord while the lid is open.

To reenable auto boot again run:
```
chattr -i /sys/firmware/efi/efivars/AutoBoot-7c436110-ab2a-4bbb-a880-fe41995c9f82
rm /sys/firmware/efi/efivars/AutoBoot-7c436110-ab2a-4bbb-a880-fe41995c9f82
```

### Links

* Excellent collection providing a status of hardware support for the MacBook
  Pro 2016 as well:
  https://gist.github.com/roadrunner2/1289542a748d9a104e7baec6a92f9cd7
