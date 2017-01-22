# State of Linux on the MacBook Pro 2016

The following document provides an overview about Linux support for the Apple
MacBook Pro 2016 line.

The MacBook Pro 2016 shares surprisingly many components with the Retina MacBook
(e.g. keyboard and touchpad controller, Wi-Fi and bluetooth chipsets, ...), so
figuring out how things work on one device should benefit both device families.

The checks if hardware work below were mostly done with Debian/unstable and
Ubuntu 16.10 with Linux 4.8 to 4.10.

## Contribution

If you want to contribute to get Linux running smoothly on the MacBook Pro 2016,
report all findings how to get devices working as pull requests! All help is
appreciated.


## Current status

| Device  | Status |
| ------- | ------ |
| [Audio input & output](#audio-input--output) | :x: not working |
| [Battery](#battery) | :heavy_check_mark: working |
| [Bluetooth](#bluetooth) | :x: not working |
| [FaceTime HD camera](#facetime-hd-camera) | :x: not working |
| [Graphics card](#graphics-card) (Intel) | :heavy_check_mark: working |
| [Graphics card](#graphics-card) (AMD) | unknown |
| [Keyboard & Touchpad](#keyboard--touchpad) | :heavy_check_mark: working with out-of-tree driver |
| [Keyboard backlight](#keyboard-backlight) | :x: not working |
| [NVMe](#nvme) (internal SSD) | :heavy_check_mark: working with out-of-tree patch |
| [Screen](#screen) | :heavy_check_mark: working |
| [Suspend & Hibernation](#suspend--hibernation) | :x: not working |
| [Temperature & fan sensors](#temperature--fan-sensors) | :heavy_check_mark: working |
| [Thunderbolt](#thunderbolt) | untested, patch available |
| [Touch Bar](#touch-bar) | :x: not working |
| [Touch ID](#touch-id) | :x: not working |
| [USB](#usb) | :heavy_check_mark: working |
| [Wi-Fi](#wi-fi) | :x: not working |


## Booting

To boot Linux properly, it's necessary to set `intremap=nosid` as kernel boot
parameter.


## Audio input & output

Not working, neither the internal speakers/microphone nor the headphone jack.

See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=110561


## Battery

Working fine, including the interface to get current capacity, temperature, etc.


## Bluetooth

Not working.

Uses the same ACPI ID `BCM2E7C` as the Retina MacBooks, so certainly it's also a
`BCM43241`.


See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=110901
* https://www.spinics.net/lists/linux-bluetooth/msg66167.html


## FaceTime HD camera

Detected at boot, but not working:
```
[    4.455993] uvcvideo: Found UVC 1.50 device iBridge (05ac:8600)
[    4.461559] uvcvideo: UVC non compliance - GET_DEF(PROBE) not supported. Enabling workaround.
[    4.462403] uvcvideo: Failed to query (129) UVC probe control : -32 (exp. 34).
[    4.464181] uvcvideo: Failed to initialize the device (-5).
[    4.466247] usbcore: registered new interface driver uvcvideo
[    4.466248] USB Video Class driver (1.1.1)
```

Uses a different USB product id (`0x8600`) than previous versions (`0x8501`). A
naive patch to enable the usual Apple iSight quirks for this product id as well,
didn't work so far.


## Graphics card

### Intel

Graphical output is working out of the box.

During boot screen becomes garbled once Linux does modeswitching,
till Xorg finally starts. As a workaround disabling KMS (`i915.modeset=0`) helps.

Connecting external displays via USB-C-to-Displayport cables is untested.

### AMD

unknown

See also:

* https://lists.freedesktop.org/archives/amd-gfx/2016-November/003673.html


## Keyboard & Touchpad

Basic keyboard and touchpad functionality is working with the out-of-tree driver
developed for the Retina Macbook (https://github.com/cb22/macbook12-spi-driver).
As described on the Github page the DSDT has to be patched to get it working.
Also ensure you have the `PXA2XX` SPI driver available:
```
CONFIG_SPI_PXA2XX=m
CONFIG_SPI_PXA2XX_PCI=m
```

After loading the driver the Touchpad isn't working from time to time. Reloading
the driver multiple times seems to fix it.

The Esc and function keys are part of the [Touch Bar](#touch-bar) and therefore
not working as of now! Also the Caps Lock LED isn't working.

Beside the actual keyboard the power button and the lid close event work out of
the box.

See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=99891
* https://bugzilla.kernel.org/show_bug.cgi?id=108331


## Keyboard backlight

Not working, it's just powered off.

Probably the ambient light sensor used for the keyboard backlight isn't
working either.


## NVMe

Isn't detected automatically, needs out-of-tree patch to work:
http://lists.infradead.org/pipermail/linux-nvme/2016-May/004618.html

Alternative workaround:
```
modprobe nvme
echo 106b 2003 > /sys/bus/pci/drivers/nvme/new_id
```

See also:
* https://unix.stackexchange.com/questions/283154/accessing-the-nvme-flash-drive-of-the-april-2016-macbook-12-a1534
* https://bugzilla.kernel.org/show_bug.cgi?id=99891


## Screen

Works out of the box including adjustable screen brightness.

The only oddity noticed so far, is that the EDID data for the 13" model
describes two modes: `2560x1600` and `2880x1800`. Xorg probes and sets the
correct resolution of `2560x1600`.
For a detailed look into the EDID data, check out
[macbook13,2/card0-eDP-1.edid](macbook13,2/card0-eDP-1.edid).


## Suspend & Hibernation

Putting the MacBook Pro into suspend mode works, but it doesn't wake up again.


## Temperature & fan sensors

Work out of the box.


## Thunderbolt

Untested, but probably working with the following patch:
https://gist.github.com/l1k/3ffbd63ac337fa85530f6db3e9ee77e9

See also:
* https://bugzilla.kernel.org/show_bug.cgi?id=189731


## Touch Bar

Not working, it's just powered off.


## Touch ID

Not working.


## USB

Works out of the box.


## Wi-Fi

* device (*Broadcom Limited BCM43602 802.11ac Wireless LAN SoC (rev 02)*) is
supported by the `brcmfmac` driver
* Only 2.4Ghz APs are shown
* Connecting to an AP barely works or fails directly
* Problem doesn't seem to be specific to the MacBook Pro 2016, probably firmware
related

See also:

* https://bugzilla.kernel.org/show_bug.cgi?id=193121
* https://bugzilla.kernel.org/show_bug.cgi?id=100201
* https://bugzilla.kernel.org/show_bug.cgi?id=103201


## Misc

### iBridge

There is one connected USB device, called *iBridge*
(*Bus 001 Device 002: ID 05ac:8600 Apple, Inc.*). It's probably the interface
to the chip running iOS and providing access to the FaceTime HD camera (that's
why `uvcvideo` detects it), the Touch Bar (that's why it's shown as an
additonal input device in the Xorg log) and the Touch ID button.
