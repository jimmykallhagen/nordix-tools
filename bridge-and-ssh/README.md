# nordix-ssh-setup, nordix-show-ip, nordix-bridge-network

Part of the [Nordix and Yggdrasil - Nordix desktop environment](https://github.com/jimmykallhagen)  
© 2025 Jimmy Källhagen - SPDX-License-Identifier: GPL-3.0-or-later

---

## Easy VM with nordix-bridge-network
 I myself found it a hassle every time I set up a machine to run VMs, so I created this to give myself and everyone else a simple network solution for their VMs.
You run nordix-bridge-network once, then you automatically fix a robust network for your VM, virt-manager will automatically use this "br0". 

 Your network setup in virt-manager should look like this after running the script: 
- Network source [Bridge device] 
- Device name [br0] 
- Device model [virtio] 

After running this script, you can use your PC as usual, it is not significantly affected by running with the Bridge network.

**How to use**
```bash
chmod +x nordix-bridge-network
sudo nordix-bridge-network
```

---

## Easy SSH with nordix-ssh-setup

nordix-ssh-setup will activate SSH and display your username and IP address in a Zenity popup, this is what you need to connect
SSH is usable for VM or if you want to be able to run commands from to phone or another computer, it is very easy to be able to use apps such as termius, to be able to get a terminal in your phone that is connected to your PC

**How to use**
```bash
chmod +x nordix-ssh-setup
sudo nordix-ssh-setup
```
---

## Easy ip-adress check 
nordix-show-ip will show your ip addresses in a zenity popup window,  this is the IP address you use for SSH

**How to use**
```bash
chmod +x nordix-show-ip
sudo nordix-show-ip
```

---

- If there is someone who feels like contributing, then all help is welcome, after all, this is to make life with Linux even better for everyone

---

## Part of Nordix

These tools are part of the Nordix/Yggdrasil toolchain.
jag täm
---
