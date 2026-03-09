# zpool-busy a tool to identify if zpool has a work in progress with trim, scrub, or resilver. 

Part of the [Nordix and Yggdrasil - Nordix desktop environment](https://github.com/jimmykallhagen)  
© 2025 Jimmy Källhagen - SPDX-License-Identifier: GPL-3.0-or-later

---

This tool is intended to act as a helper for other tools, it is possible to use it manually, if you want that too. It's a left over from when I developed nordix-graceful-shutdown

when you run zpool-busy, there are 4 responses you can get 

  * scrub 
  * resilver 
  * trim 
  * none

---

## Part of Nordix

These tools are part of the Nordix/Yggdrasil toolchain.