# State of Linux on the MacBook Pro 2016 & 2017

The following document provides an overview about Linux support for Apple's
MacBook Pro 2016 and MacBook Pro 2017 models.

The MacBook Pro 2016 shares surprisingly many components with the Retina
MacBook (e.g. keyboard and touchpad controller, Wi-Fi and bluetooth chipsets,
...), so figuring out how things work on one device should benefit both device
families.

The Apple MacBook Pro 2017 models are nearly identical to their 2016
counterparts, except for the use of newer Intels Kaby Lake processors instead
of Intel Skylake processors, faster memory and updated AMD Radeon GPUs in the
15-inch models.

The checks if hardware works below were done with multiple Linux distributions.
To state the obvious: The newer the kernel the better. If in doubt which kernel
to use, the latest significant improvements are part of Linux 4.16.

If you don't know what the model identifier for your MacBook Pro is (as that
identifier is used on several occasions below), check
https://support.apple.com/en-us/HT201300


## Contribution

If you want to contribute to get Linux running smoothly on the MacBook Pro
2016, report all findings how to get devices working as pull requests! All help
is appreciated.


## Current status

| Device  | Status |
| ------- | ------ |
| [Audio input & output](#audio-input--output) | ![all models not working](https://img.shields.io/badge/all_models-not_working-red.svg) |
| [Battery](#battery) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Bluetooth](#bluetooth) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [FaceTime HD camera](#facetime-hd-camera) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Graphics card](#intel) (Intel) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Graphics card](#amd) (AMD) | ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg) |
| [Keyboard & Touchpad](#keyboard--touchpad) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [NVMe](#nvme) (internal SSD) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Screen](#screen) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Suspend & Hibernation](#suspend--hibernation) |![all models not working](https://img.shields.io/badge/all_models-not_working-red.svg) |
| [System Management Controller](#system-management-controller) | ![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 partially working](https://img.shields.io/badge/MacBookPro13%2C2-partially_working-yellow.svg) ![MacBookPro13,3 partially working](https://img.shields.io/badge/MacBookPro13%2C3-partially_working-yellow.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 partially working](https://img.shields.io/badge/MacBookPro14%2C2-partially_working-yellow.svg) ![MacBookPro14,3 partially working](https://img.shields.io/badge/MacBookPro14%2C3-partially_working-yellow.svg) |
| [Thunderbolt](#thunderbolt) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Touch Bar](#touch-bar) | ![MacBookPro13,2 partially working](https://img.shields.io/badge/MacBookPro13%2C2-partially_working-yellow.svg) ![MacBookPro13,3 partially working](https://img.shields.io/badge/MacBookPro13%2C3-partially_working-yellow.svg) ![MacBookPro14,2 partially working](https://img.shields.io/badge/MacBookPro14%2C2-partially_working-yellow.svg) ![MacBookPro14,3 partially working](https://img.shields.io/badge/MacBookPro14%2C3-partially_working-yellow.svg) |
| [Touch ID](#touch-id) | ![MacBookPro13,2 not working](https://img.shields.io/badge/MacBookPro13%2C2-not_working-red.svg) ![MacBookPro13,3 not working](https://img.shields.io/badge/MacBookPro13%2C3-not_working-red.svg) ![MacBookPro14,2 not working](https://img.shields.io/badge/MacBookPro14%2C2-not_working-red.svg) ![MacBookPro14,3 not working](https://img.shields.io/badge/MacBookPro14%2C3-not_working-red.svg) |
| [USB](#usb) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Wi-Fi](#wi-fi) | ![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 not working](https://img.shields.io/badge/MacBookPro13%2C2-not_working-red.svg) ![MacBookPro13,3 not working](https://img.shields.io/badge/MacBookPro13%2C3-not_working-red.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 not working](https://img.shields.io/badge/MacBookPro14%2C2-not_working-red.svg) ![MacBookPro14,3 not working](https://img.shields.io/badge/MacBookPro14%2C3-not_working-red.svg) |


## Booting

To boot Linux version earlier than 4.10 properly, it's necessary to set
`intremap=nosid` as kernel boot parameter. From 4.10 onwards that's not
necessary anymore.


## Audio input & output

![MacBookPro13,1 not working](https://img.shields.io/badge/MacBookPro13%2C1-not_working-red.svg) ![MacBookPro13,2 not working](https://img.shields.io/badge/MacBookPro13%2C2-not_working-red.svg) ![MacBookPro13,3 not working](https://img.shields.io/badge/MacBookPro13%2C3-not_working-red.svg) ![MacBookPro14,1 not working](https://img.shields.io/badge/MacBookPro14%2C1-not_working-red.svg) ![MacBookPro14,2 not working](https://img.shields.io/badge/MacBookPro14%2C2-not_working-red.svg) ![MacBookPro14,3 not working](https://img.shields.io/badge/MacBookPro14%2C3-not_working-red.svg)

Not working, neither the internal speakers/microphone nor the headphone jack.

What's working is audio via HDMI or any USB-connected audio device, so that can
act as a workaround until internal audio is working.

See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=195671
* https://bugzilla.kernel.org/show_bug.cgi?id=110561


## Battery

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Working fine, including the interface to get current capacity, temperature,
etc.

Battery life is still suboptimal, because power saving modes for several
devices, like display (panel self refresh), SSD or the Thunderbolt
controllers, aren't working yet. You can expected a battery life of less
than 4 hours.

## Bluetooth

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Works out of the box with Linux 4.16 and above, except for the models without
Touch Bar, which still suffer from a bug and need an additional patch as noted
in https://github.com/Dunedan/mbp-2016-linux/issues/29#issuecomment-371370548

For older kernel versions you need to compile a custom kernel with an
additional patch set. For details check
https://github.com/Dunedan/mbp-2016-linux/issues/29

See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=110901

## FaceTime HD camera

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

In the MacBookPro13,1 (without Touch Bar) the FaceTime HD camera is connected
via PCIe, like in previous MacBook Pro's. It's working with the
[`bcwc_pcie`](https://github.com/patjak/bcwc_pcie/wiki) driver.

The models with Touch Bar have the FaceTime HD camera connected through the
iBridge device via USB. They are exposed as regular USB video devices and are
supported by the `uvcvideo` driver starting with Linux 4.13 out of the box.
Previous Linux versions need the following quirk for `uvcvideo` to get them to
work properly:

```
echo "options uvcvideo quirks=0x100" > /etc/modprobe.d/uvcvideo.conf
```


## Graphics card

### Intel

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

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

![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Working since Linux 4.9.

See also:

* https://gist.github.com/roadrunner2/1289542a748d9a104e7baec6a92f9cd7#gistcomment-1981040
* https://lists.freedesktop.org/archives/amd-gfx/2016-November/003673.html


## Keyboard & Touchpad

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Basic keyboard and touchpad functionality is working with the out-of-tree
driver developed for the Retina Macbook
(https://github.com/cb22/macbook12-spi-driver).

The Esc and function keys are part of the Touch Bar in all Touch Bar-models, so
follow the instructions for the [Touch Bar](#touch-bar) to get it working.

Beside the actual keyboard the power button and the lid close event work out of
the box.

Palm rejection based on touch-sizes and disable-touchpad-while-typing are working 
with [this patch](https://gist.github.com/peterychuang/5cf9bf527bc26adef47d714c758a5509)
to [libinput](https://cgit.freedesktop.org/wayland/libinput) (master branch).

See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=99891
* https://bugzilla.kernel.org/show_bug.cgi?id=108331


## NVMe

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

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

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

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

![MacBookPro13,1 not working](https://img.shields.io/badge/MacBookPro13%2C1-not_working-red.svg) ![MacBookPro13,2 not working](https://img.shields.io/badge/MacBookPro13%2C2-not_working-red.svg) ![MacBookPro13,3 not working](https://img.shields.io/badge/MacBookPro13%2C3-not_working-red.svg) ![MacBookPro14,1 not working](https://img.shields.io/badge/MacBookPro14%2C1-not_working-red.svg) ![MacBookPro14,2 not working](https://img.shields.io/badge/MacBookPro14%2C2-not_working-red.svg) ![MacBookPro14,3 not working](https://img.shields.io/badge/MacBookPro14%2C3-not_working-red.svg)

Putting the MacBook Pro into suspend mode works, but it doesn't wake up again.
@roadrunner2 did some work in this area. You'll find some details about it in
https://github.com/cb22/macbook12-spi-driver/pull/30#issuecomment-306316034


## System Management Controller

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 partially working](https://img.shields.io/badge/MacBookPro13%2C2-partially_working-yellow.svg) ![MacBookPro13,3 partially working](https://img.shields.io/badge/MacBookPro13%2C3-partially_working-yellow.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 partially working](https://img.shields.io/badge/MacBookPro14%2C2-partially_working-yellow.svg) ![MacBookPro14,3 partially working](https://img.shields.io/badge/MacBookPro14%2C3-partially_working-yellow.svg)

The System Management Controller is responsible for interactions with sensors,
fans.

Fans, temperature and voltage sensors work out of the box using the `applesmc`
kernel module, while the ambient light sensors only work in the MacBookPro13,1.

An accelerometer doesn't seem to be available at all.


## Thunderbolt

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Works out of the box with Linux 4.13 and above.

Tested on a MacBookPro13,3 with a HP Thunderbolt 3 Dock. DisplayPort with a 4k
Display with 60 Hz works via the dock. The (PCI) Ethernet inside the dock and
USB/audio from the dock work too.


## Touch Bar

![MacBookPro13,2 partially working](https://img.shields.io/badge/MacBookPro13%2C2-partially_working-yellow.svg) ![MacBookPro13,3 partially working](https://img.shields.io/badge/MacBookPro13%2C3-partially_working-yellow.svg) ![MacBookPro14,2 partially working](https://img.shields.io/badge/MacBookPro14%2C2-partially_working-yellow.svg) ![MacBookPro14,3 partially working](https://img.shields.io/badge/MacBookPro14%2C3-partially_working-yellow.svg)

Not working out of the box, but thanks to @roadrunner2 basic functionality
is working using the driver you can find at:
https://github.com/roadrunner2/macbook12-spi-driver/blob/touchbar-driver-hid-driver/appletb.c

Missing is as of now just the advanced functionality with custom graphics Apple
offers in macOS.


## Touch ID

![MacBookPro13,2 not working](https://img.shields.io/badge/MacBookPro13%2C2-not_working-red.svg) ![MacBookPro13,3 not working](https://img.shields.io/badge/MacBookPro13%2C3-not_working-red.svg) ![MacBookPro14,2 not working](https://img.shields.io/badge/MacBookPro14%2C2-not_working-red.svg) ![MacBookPro14,3 not working](https://img.shields.io/badge/MacBookPro14%2C3-not_working-red.svg)

Not working.


## USB

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Works out of the box.


## Wi-Fi

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 not working](https://img.shields.io/badge/MacBookPro13%2C2-not_working-red.svg) ![MacBookPro13,3 not working](https://img.shields.io/badge/MacBookPro13%2C3-not_working-red.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 not working](https://img.shields.io/badge/MacBookPro14%2C2-not_working-red.svg) ![MacBookPro14,3 not working](https://img.shields.io/badge/MacBookPro14%2C3-not_working-red.svg)

The MacBook Pro models without Touch Bar come with a `Broadcom Limited BCM4350
802.11ac Wireless Network Adapter` which works fine out of the box using the
`brcmfmac` driver (ensure you got the matching firmware package installed).

The MacBook Pro models with Touch Bar come with a `Broadcom Limited BCM43602
802.11ac Wireless LAN SoC (rev 02)` which is also supported by `brcmfmac`, but
has several issues rendering it unusable, caused by the available firmware.
The issues are caused by failing country detection and are:
* Only 2.4Ghz APs are shown
* Connecting to an AP barely works or fails directly

According to Broadcom releasing a fixed firmware would require verification to
ensure that it complies with regulartory limits, which is very unlikely to
happen as it wouldn't provide enough return on investment for them (see
https://bugzilla.kernel.org/show_bug.cgi?id=193121 for details).

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
  out of the box (the one in the MacBookPro13,3 was already working before).
  ([linux/commit/124298b](https://github.com/torvalds/linux/commit/124298bd03acebd9c9da29a794718aca31bec1f7))
* When booting with kernel modesetting (KMS) the screen isn't scrambled during
  boot anymore.

#### 4.13

* On the Touch Bar models the FaceTime HD camera is working out of the box.
  ([linux/commit/7b848ed](https://github.com/torvalds/linux/commit/7b848ed60f409ce860023c79aa9a5c8d1833ebab))
* Adds support for the Alpine Ridge 4C Thunderbolt Chip used in the MacBook Pro's
  ([linux/commit/5e2781b](https://github.com/torvalds/linux/commit/5e2781bcb1e876d314832489ff8177ef917d9b45))

#### 4.14

* Includes the foundation for upstreaming the
  [`applespi`](https://github.com/cb22/macbook12-spi-driver)-driver.
  ([linux/commit/ca9ef3a](https://github.com/torvalds/linux/commit/ca9ef3ab68d3530ac93d4254f9e47724ea51758d),
  [linux/commit/899596e](https://github.com/torvalds/linux/commit/899596e090ea21918c55cbccea594be840af44ea),
  [linux/commit/75fc70e](https://github.com/torvalds/linux/commit/75fc70e07314347465c7df6d6b79535cf3db0e2a),
  [linux/commit/630b3af](https://github.com/torvalds/linux/commit/630b3aff8a51c90ef15b59c9560ac35e40e7ec09))

#### 4.16

* Bluetooth is now working out of the box.
  ([linux/commit/8353b4a](https://github.com/torvalds/linux/commit/8353b4a636f2c83de748656acc6b6a8757d7a0ff),
  [linux/commit/8bfa7e1](https://github.com/torvalds/linux/commit/8bfa7e1e03aca3626b82857850a1e18ae0ed291d),
  [linux/commit/4c33162](https://github.com/torvalds/linux/commit/4c33162c1ad0d3524455d6c10de2a05847ad5617))

### iBridge

The models with Touch Bar feature an additional USB device, called `iBridge`
(`Bus 001 Device 002: ID 05ac:8600 Apple, Inc.`). It's the interface to the
embedded T1-chip running iOS and providing access to the FaceTime HD camera,
the Touch Bar and Touch ID.

A prerequisite for all devices connected to the iBridge to work is a
firmware stored by macOS on the EFI system partition (ESP). For the time being
the easiest way to keep this firmware available is to install Linux in
addition to macOS and keeping the contents of the original ESP in place.

If the iBridge couldn't be initialized (e.g. because the firmware is
missing), instead of the usual USB device, the following USB device is
present: `Apple Mobile Device [Recovery Mode]` (`Bus 001 Device 003: ID
05ac:1281 Apple, Inc.`)

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
