#!/bin/bash

if ! [ -x "$(command -v hwinfo)" ]; then
  echo "Can't find hwinfo. Please install it." >&2
  exit 1
fi
if ! [ -x "$(command -v acpidump)" ]; then
  echo "Can't find acpidump. Please install it." >&2
  exit 1
fi

name=$(</sys/class/dmi/id/product_name)

dir="${0%/*}/$name"
mkdir -p "$dir"

echo "getting EDID for card0-eDP-1"
cp /sys/class/drm/card0-eDP-1/edid "$dir"/card0-eDP-1.edid

echo "getting dmesg"
sudo dmesg > "$dir"/dmesg

echo "getting hwinfo"
sudo hwinfo > "$dir"/hwinfo.txt

echo "getting lspci"
sudo lspci -vvnn > "$dir"/lspci

echo "getting lsusb"
sudo lsusb -v > "$dir"/lsusb

echo "getting Xorg.log"
user_log=~/.local/share/xorg/Xorg.0.log
global_log=/var/log/Xorg.0.log
if [ $user_log -nt $global_log ]; then
    cp $user_log "$dir"/Xorg.0.log
else
    cp $global_log "$dir"/Xorg.0.log
fi

echo "getting ACPI tables"
sudo acpidump > "$dir"/acpidump

echo "done!"
