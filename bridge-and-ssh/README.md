# nordix-ssh-setup, nordix-show-ip, nordix-bridge-network

Part of the [Nordix and Yggdrasil - Nordix desktop environment](https://github.com/jimmykallhagen)  
© 2025 Jimmy Källhagen - SPDX-License-Identifier: GPL-3.0-or-later

---

## Easy VM with nordix-bridge-network
I developed these myself because I thought it would be easier for everyone who wants to run VM, you run nordix-bridge-network once, then you automatically fix a robust network for your VM, virt-manager will automatically use this "br0". 

Your network setup in Virtmanager should look like this after you have used the script: 
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

nordix-ssh-setup will activate SSH and show your username and ip-addres in a zenity popup window, this is what you use for SSH.
SSH is usable for VM or if you want to be able to run commands from to phone or another computer, it is very easy to be able to use apps such as termius, to be able to get a terminal in your phone that is connected to your PC

**How to use**
```bash
chmod +x nordix-ssh-setup
sudo nordix-ssh-setup
```
---

## Easy ip-adress check 
nordix-show-ip will show your ip addresses in a zenity popup window, this is your ip address you use for ssh

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

---