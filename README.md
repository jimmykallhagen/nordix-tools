# ![nordix-tools-icon](https://github.com/jimmykallhagen/Nordix/blob/main/icons/hicolor/128x128/apps/nordix-term.png) **Nordix Tools**

**Part of:** [Nordix](https://github.com/jimmykallhagen/Nordix)  
**Author:** Jimmy Källhagen  
**License:** PolyForm-Noncommercial-1.0.0

---

1. **nordix-bridge-network**
 - easy way to set up a bridge network to use when running VM, just run the script and virtmanager will now automatically get a working network for the VM.

---

3. [**nx-cpu-logic**](README-nx-cpu-logic.md)
- Simple helper to see how your CPU cores are paired with their threads.

---

4. **nx-show-ip**
- Easily displays your current IP address in a zenity, useful for ssh and so on.

---

6. **nordix-ssh-setup**
- Installs and activates ssh easily without any hassle, then displays your username and IP address for ssh in a zenity when the script is finished. must be run with sudo

---

7. **nx-cp**
- cp and move are processes that run single core. by forcing these processes to use two physical cores we can now give breathing room and maintain a higher boost clock without thermal throttling. these tools also show transfer speed and progress.
this tool also sees how many cores your cpu has and then uses the last two physical cores to avoid burdening the first cores that your system is using.

---

8. **nx-mv**
- cp and move are processes that run single core. by forcing these processes to use two physical cores we can now give breathing room and maintain a higher boost clock without thermal throttling. these tools also show transfer speed and progress.
this tool also sees how many cores your cpu has and then uses the last two physical cores to avoid burdening the first cores that your system is using.

---

9. **zfs-destroy-snapshots**
- When using zfs with snapshots, it is easy to overfill your storage space and you may therefore need to clear snapshots, this takes time and is unnecessarily complicated to do manually, with zfs-destroy-snapshot you can now quickly clear your snapshots.

---

10. **nordix-sock-call**

- A tool to use when you need to activate a socket
- Usage: nordix-sock-call /socket-path message

**Build**
```bash
clang -o nordix-sock-call nordix-sock-call.c
```
---

## How to install
```bash
mkdir ~/builds
cd ~/builds
git clone https://github.com/jimmykallhagen/nordix-tools.git
sudo mkdir -p /usr/lib/nordix/bin
sudo cp -r ~/builds/nordix-tools/usr
echo 'export PATH="/usr/lib/nordix/bin:$PATH"' >> ~/.profile
```
---

## How to make nx-cp and nx-mv alias for cp and mv

For fish shell
```bash
echo "alias mv='nx-mv'" >> ~/.config/fish/config.fish
echo "alias cp='nx-cp'" >> ~/.config/fish/config.fish
```

For bash shell
```bash
echo "alias mv='nx-mv'" >> ~/.bashrc
echo "alias cp='nx-cp'" >> ~/.bashrc
```

For zsh
```bash
echo "alias mv='nx-mv'" >> ~/.zshenv
echo "alias cp='nx-cp'" >> ~/.zshenv
```
---
