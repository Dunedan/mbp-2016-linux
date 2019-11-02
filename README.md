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
To state the obvious: The newer the kernel the better. The information below
assumes that you run Linux 4.13 or newer. If in doubt which kernel to use, the
latest significant improvements are part of Linux 5.3.

If you don't know what the model identifier for your MacBook Pro is (as that
identifier is used on several occasions below), check
https://support.apple.com/en-us/HT201300

## Contribution

If you want to contribute to get Linux running smoothly on the MacBook Pro
2016, report all findings on how to get devices working as pull requests! All help
is appreciated.

There is also a chat available via gitter for discussions:
[![Gitter chat](https://badges.gitter.im/Dunedan/mbp-2016-linux.png)](https://gitter.im/mbp-2016-linux/Lobby)

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
| [Suspend & Hibernation](#suspend--hibernation) |![all models partially working](https://img.shields.io/badge/all_models-partially_working-yellow.svg) |
| [System Management Controller](#system-management-controller) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Thunderbolt](#thunderbolt) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Touch Bar](#touch-bar) | ![MacBookPro13,2 partially working](https://img.shields.io/badge/MacBookPro13%2C2-partially_working-yellow.svg) ![MacBookPro13,3 partially working](https://img.shields.io/badge/MacBookPro13%2C3-partially_working-yellow.svg) ![MacBookPro14,2 partially working](https://img.shields.io/badge/MacBookPro14%2C2-partially_working-yellow.svg) ![MacBookPro14,3 partially working](https://img.shields.io/badge/MacBookPro14%2C3-partially_working-yellow.svg) |
| [Touch ID](#touch-id) | ![MacBookPro13,2 not working](https://img.shields.io/badge/MacBookPro13%2C2-not_working-red.svg) ![MacBookPro13,3 not working](https://img.shields.io/badge/MacBookPro13%2C3-not_working-red.svg) ![MacBookPro14,2 not working](https://img.shields.io/badge/MacBookPro14%2C2-not_working-red.svg) ![MacBookPro14,3 not working](https://img.shields.io/badge/MacBookPro14%2C3-not_working-red.svg) |
| [USB](#usb) | ![all models working](https://img.shields.io/badge/all_models-working-green.svg) |
| [Wi-Fi](#wi-fi) | ![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 not working](https://img.shields.io/badge/MacBookPro13%2C2-not_working-red.svg) ![MacBookPro13,3 not working](https://img.shields.io/badge/MacBookPro13%2C3-not_working-red.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 not working](https://img.shields.io/badge/MacBookPro14%2C2-not_working-red.svg) ![MacBookPro14,3 not working](https://img.shields.io/badge/MacBookPro14%2C3-not_working-red.svg) |

## Audio input & output

![MacBookPro13,1 not working](https://img.shields.io/badge/MacBookPro13%2C1-not_working-red.svg) ![MacBookPro13,2 not working](https://img.shields.io/badge/MacBookPro13%2C2-not_working-red.svg) ![MacBookPro13,3 not working](https://img.shields.io/badge/MacBookPro13%2C3-not_working-red.svg) ![MacBookPro14,1 not working](https://img.shields.io/badge/MacBookPro14%2C1-not_working-red.svg) ![MacBookPro14,2 not working](https://img.shields.io/badge/MacBookPro14%2C2-not_working-red.svg) ![MacBookPro14,3 not working](https://img.shields.io/badge/MacBookPro14%2C3-not_working-red.svg)

Not working, neither the internal speakers/microphone nor the headphone jack.

What's working is audio via HDMI or any USB-connected audio device, so that can
act as a workaround until internal audio is working.

See also:

* https://bugzilla.kernel.org/show_bug.cgi?id=195671
* https://bugzilla.kernel.org/show_bug.cgi?id=110561
* http://mailman.alsa-project.org/pipermail/alsa-devel/2018-November/141942.html

## Battery

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Working fine, including the interface to get current capacity, temperature,
etc.

Battery life is still suboptimal, because power saving modes for several
devices, like display (panel self refresh), SSD or the Thunderbolt
controllers, aren't working yet. You can expect a battery life of less
than 4 hours.

## Bluetooth

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Works out of the box with Linux 4.16 and above, except for the models without
Touch Bar, which still suffers from a bug and needs an additional patch as noted
in https://github.com/Dunedan/mbp-2016-linux/issues/29#issuecomment-371370548

Transmitting audio using A2DP is still choppy for unknown reasons, maybe
because the Bluetooth support is limited to lower bandwidth applications so
far.

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
supported by the `uvcvideo` driver out of the box.

## Graphics card

### Intel

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Graphical output using the Intel GPU is working out of the box on the
MacBookPro 13,1 and 13,2, without dedicated AMD GPU. For the MacBookPro 13,3
with dedicated AMD GPU, only the AMD GPU is enabled when booting an OS which
isn't macOS, so you have to follow the instructions in the following link to
enable the integrated Intel GPU, if you want to use it:
https://github.com/Dunedan/mbp-2016-linux/issues/6#issuecomment-286168538

Connecting external displays via USB-C-to-DisplayPort cables works fine,
including connections with daisy-chaining/MST. An actual tested and working
setup includes concurrent output on the internal display and two external
displays daisy-chained together with Full HD each.

### AMD

![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Works out of the box.

## Keyboard & Touchpad

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Works out of the box with Linux 5.3 and above.

For earlier Linux versions you can get the driver from
https://github.com/roadrunner2/macbook12-spi-driver.

The Esc and function keys are part of the Touch Bar in all Touch Bar-models, so
follow the instructions for the [Touch Bar](#touch-bar) to get it working.

Beside the actual keyboard, the power button and the lid close event work out of
the box.

Palm rejection based on touch-sizes and disable-touchpad-while-typing are working
with [this patch](https://gist.github.com/peterychuang/5cf9bf527bc26adef47d714c758a5509)
to [libinput](https://cgit.freedesktop.org/wayland/libinput) (master branch).

See also:

* https://bugzilla.kernel.org/show_bug.cgi?id=99891
* https://bugzilla.kernel.org/show_bug.cgi?id=108331

## NVMe

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Works out of the box.

The SSDs used in the MacBook Pros don't seem to support APST. As it's currently
unknown how power saving works for those SSDs it's likely they consume way more
power than they need to, therefore reducing the battery life.

## Screen

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Works out of the box.

Adjustable screen brightness only works out of the box for the models without
additional AMD Radeon GPU (MacBookPro13,1 and MacBookPro13,2). For the
MacBookPro13,3 with additional AMD Radeon GPU the following patch is necessary:
https://bugzilla.kernel.org/show_bug.cgi?id=105051#c32

There is one oddity in the EDID data of the 13" models, as it contains a
`2800x1800` mode in addition to the correct `2560x1600` mode. In the end that
doesn't matter, as Xorg probes and sets the correct resolution of `2560x1600`.

## Suspend & Hibernation

![MacBookPro13,1 partially working](https://img.shields.io/badge/MacBookPro13%2C1-partially_working-yellow.svg) ![MacBookPro13,2 partially working](https://img.shields.io/badge/MacBookPro13%2C2-partially_working-yellow.svg) ![MacBookPro13,3 partially working](https://img.shields.io/badge/MacBookPro13%2C3-partially_working-yellow.svg) ![MacBookPro14,1 partially working](https://img.shields.io/badge/MacBookPro14%2C1-partially_working-yellow.svg) ![MacBookPro14,2 partially working](https://img.shields.io/badge/MacBookPro14%2C2-partially_working-yellow.svg) ![MacBookPro14,3 partially working](https://img.shields.io/badge/MacBookPro14%2C3-partially_working-yellow.svg)

Putting the MacBook Pro into suspend mode works on all models, but successful
resume requires additional prerequisites as explained below.

Models with Apple's NVMe controller (MacBookPro13,1, MacBookPro13,2,
MacBookPro14,1 and MacBookPro14,2) require disabling the `d3cold` PCIe power
state for the NVMe controller to successfully wake up again:

```
echo 0 > /sys/bus/pci/devices/0000\:01\:00.0/d3cold_allowed
```

Even then resume is incredible slow and takes up to a minute, probably due to
additional bugs.

For the 15" models with additional AMD GPU resume only works when using the
internal Intel GPU.

## System Management Controller

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

The System Management Controller (SMC) is responsible for interactions with
sensors and fans.

Fans, temperature and voltage sensors work out of the box using the `applesmc`
kernel module.

Even though the MacBook Pro manages fan speed automatically,
manually setting the fan speed through `applesmc` works as well. That's useful
if you want to use a different fan speed profile than the hardware uses by
default. In that case, you might want to use a tool like
[`mbpfan`](https://github.com/dgraziotin/mbpfan).

The ambient light sensor is working out of the box for the models without Touch
Bar, using the `applesmc` module as well. In models with Touch Bar, the ambient
light sensor isn't connected to the traditional SMC, but to the iBridge
instead. For it to function, you need the third-party `apple-ib-als` kernel
module you can find in the following git repository:
https://github.com/roadrunner2/macbook12-spi-driver

An accelerometer isn't available at all.

## Thunderbolt

![MacBookPro13,1 working](https://img.shields.io/badge/MacBookPro13%2C1-working-green.svg) ![MacBookPro13,2 working](https://img.shields.io/badge/MacBookPro13%2C2-working-green.svg) ![MacBookPro13,3 working](https://img.shields.io/badge/MacBookPro13%2C3-working-green.svg) ![MacBookPro14,1 working](https://img.shields.io/badge/MacBookPro14%2C1-working-green.svg) ![MacBookPro14,2 working](https://img.shields.io/badge/MacBookPro14%2C2-working-green.svg) ![MacBookPro14,3 working](https://img.shields.io/badge/MacBookPro14%2C3-working-green.svg)

Works out of the box.

Up to now power management support for the Thunderbolt controllers isn't
complete yet, resulting in unnecessary battery drain when no devices are
attached to the Thunderbolt ports.

## Touch Bar

![MacBookPro13,2 partially working](https://img.shields.io/badge/MacBookPro13%2C2-partially_working-yellow.svg) ![MacBookPro13,3 partially working](https://img.shields.io/badge/MacBookPro13%2C3-partially_working-yellow.svg) ![MacBookPro14,2 partially working](https://img.shields.io/badge/MacBookPro14%2C2-partially_working-yellow.svg) ![MacBookPro14,3 partially working](https://img.shields.io/badge/MacBookPro14%2C3-partially_working-yellow.svg)

Not working out of the box, but thanks to @roadrunner2 basic functionality
is working using the `apple-ib-tb` kernel module you can find in the following
git repository: https://github.com/roadrunner2/macbook12-spi-driver

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
ensure that it complies with regulatory limits, which is very unlikely to
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

#### 4.20

* Fixes a garbled screen issue with Intel graphics when using KMS, introduced
  with Linux 4.18.
  ([linux/commit/d9a5158](https://github.com/torvalds/linux/commit/d9a515867bdba59ebf196a6ade10faae8e8be36a))
* Fixes a black screen issue for models with AMD graphics, introduced with
  Linux 4.18.
  ([linux/commit/07e3a1c](https://github.com/torvalds/linux/commit/07e3a1cfb0568b6d8d7862077029af96af6690ea))
* Fixes a GPE storm, which caused unnecessary battery drain.
  ([linux/commit/ca1721c](https://github.com/torvalds/linux/commit/ca1721c5bee77105829cbd7baab8ee0eab85b06d))

#### 5.1

* Fixes a regression introduced with Linux 4.17 with prevented the MacBook
  Pro's without Touch Bar to boot.
  ([linux/commit/6f913de](https://github.com/torvalds/linux/commit/6f913de3231e1d70a871135b38219da7810df218))

#### 5.3

* The `applespi` driver for the internal keyboard and trackpad of the
  MacBookPro13,* and MacBookPro14,* is now included upstream and works out of
  the box.
  ([linux/commit/038b1a0](https://github.com/torvalds/linux/commit/038b1a05eae6666b731920e46f47d8e2332e07ff))

### iBridge

The models with Touch Bar feature an additional USB device, called `iBridge`
(`Bus 001 Device 002: ID 05ac:8600 Apple, Inc.`). It's the interface to the
embedded T1-chip running iOS and providing access to the ambient light sensor,
the FaceTime HD camera, the Touch Bar and Touch ID.

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
T:  Bus=01 Lev=01 Prnt=01 Port=02 Cnt=01 Dev#=  2 Spd=480 MxCh= 0
D:  Ver= 2.00 Cls=ef(misc ) Sub=02 Prot=01 MxPS=64 #Cfgs=  3
P:  Vendor=05ac ProdID=8600 Rev=01.01
S:  Manufacturer=Apple Inc.
S:  Product=iBridge
C:  #Ifs= 4 Cfg#= 1 Atr=e0 MxPwr=0mA
I:  If#= 0 Alt= 0 #EPs= 0 Cls=0e(video) Sub=01 Prot=00 Driver=uvcvideo
I:  If#= 1 Alt= 0 #EPs= 1 Cls=0e(video) Sub=02 Prot=00 Driver=uvcvideo
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
C:  #Ifs= 8 Cfg#= 2 Atr=e0 MxPwr=0mA
I:  If#= 0 Alt= 0 #EPs= 0 Cls=0e(video) Sub=01 Prot=00 Driver=usbfs
I:  If#= 1 Alt= 0 #EPs= 1 Cls=0e(video) Sub=02 Prot=00 Driver=usbfs
I:  If#= 2 Alt= 0 #EPs= 1 Cls=03(HID  ) Sub=00 Prot=01 Driver=usbfs
I:  If#= 3 Alt= 0 #EPs= 2 Cls=10() Sub=00 Prot=00 Driver=usbfs
I:  If#= 4 Alt= 0 #EPs= 0 Cls=02(commc) Sub=0d Prot=00 Driver=usbfs
I:  If#= 5 Alt= 1 #EPs= 2 Cls=0a(data ) Sub=00 Prot=01 Driver=usbfs
I:  If#= 6 Alt= 0 #EPs= 1 Cls=03(HID  ) Sub=00 Prot=01 Driver=usbfs
I:  If#= 7 Alt= 0 #EPs= 2 Cls=ff(vend.) Sub=f9 Prot=11 Driver=usbfs
```

macOS somehow initializes some additional capabilities of the *iBridge*.
Those additional interfaces are likely responsible for Touch Id and the
advanced graphical functionality of the Touch Bar. There might also be some
kind of interface for *iBridge*-firmware updates.

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

To re-enable auto boot again run:

```
chattr -i /sys/firmware/efi/efivars/AutoBoot-7c436110-ab2a-4bbb-a880-fe41995c9f82
rm /sys/firmware/efi/efivars/AutoBoot-7c436110-ab2a-4bbb-a880-fe41995c9f82
```

### Links

* Excellent collection providing a status of hardware support for the MacBook
  Pro 2016 as well:
  https://gist.github.com/roadrunner2/1289542a748d9a104e7baec6a92f9cd7
