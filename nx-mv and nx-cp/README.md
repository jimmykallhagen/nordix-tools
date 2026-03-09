# nx-mv / nx-cp

**Nordix CPU-aware wrappers for `mv` and `cp`**

Part of the [Yggdrasil – Nordix desktop environment](https://github.com/jimmykallhagen)  
© 2025 Jimmy Källhagen - SPDX-License-Identifier: GPL-3.0-or-later

---

## What is this?

`nx-mv` and `nx-cp` are drop-in replacements for the standard `mv` and `cp` commands.  
They use `taskset` to pin the process to the **two last physical CPU cores**, allowing the OS scheduler to move the process between them for sustained thermal performance.

---

## The Theory

`mv` and `cp` are single-threaded processes. On a modern CPU with boost clocks, a single core doing sustained I/O work will quickly heat up and begin thermal throttling — the CPU lowers its clock speed to stay within temperature limits, and transfer speed drops.

The naive solution might be to give the process access to many cores. Empirical testing showed the opposite: pinning to **16 cores gave worse performance than pinning to 2**. The reason is scheduler overhead — with many cores available, the Linux scheduler migrates the process frequently as it finds "cooler" candidates. Each migration invalidates the L1/L2 cache for that process, and the cost of warming up cache on the new core outweighs the thermal benefit.

**With exactly two cores**, the behavior is different:

1. The process runs on core A at full boost clock
2. Core A heats up toward its thermal limit
3. The scheduler migrates the process to core B, which is cool and boosts immediately
4. Core A recovers while core B works
5. The cycle repeats

Migrations happen rarely enough that cache stays warm, but frequently enough that neither core sustains a thermal throttle. The result is a higher **average** clock speed over the duration of the transfer compared to both single-core and many-core pinning.

This is essentially manual **thermal-aware core parking** - not driven by power policy, but by giving the scheduler just enough room to breathe without drowning in cache misses.

---

## Why the last two physical cores?

The first physical cores (core 0, core 1) are where the OS, interrupt handlers, and system processes naturally concentrate their work. On a system tuned with `nohz_full`, those first cores are explicitly reserved for the kernel.

The **last physical cores** are typically the coolest and least loaded cores on the system - ideal candidates to absorb a sustained single-threaded workload without disturbing anything else.

---

## CPU Topology Detection

Both tools read CPU topology directly from the kernel via `/sys/devices/system/cpu/cpuN/topology/core_id` rather than assuming sequential logical core numbering.

This matters because on AMD Zen (and other architectures), logical cores are **not** assigned in a simple `physical_core * 2` pattern. On an R9 7950X for example:

| Physical Core | Logical Threads |
|---|---|
| Core 14 | 14 and 30 |
| Core 15 | 15 and 31 |

A naive calculation of `last_core * 2` would produce the wrong result. By reading the topology map, the tools correctly identify the **first thread** (lowest logical ID) of each of the two last physical cores, regardless of CPU architecture or thread count.

SMT siblings (the second thread of each physical core) are intentionally excluded from the `taskset` - two cores from different physical dies is more effective for thermal rotation than two threads sharing the same physical core and thermal unit.

---

## Installation

```bash
sudo cp nx-mv /usr/local/bin/nx-mv
sudo cp nx-cp /usr/local/bin/nx-cp
sudo chmod +x /usr/local/bin/nx-mv
sudo chmod +x /usr/local/bin/nx-cp
```

---

## Shell Aliases

### Fish (`~/.config/fish/config.fish`)

```fish
alias mv='nx-mv'
alias cp='nx-cp'
```

### Bash (`~/.bashrc`)

```bash
alias mv='nx-mv'
alias cp='nx-cp'
```

### Zsh (`~/.zshrc`)

```zsh
alias mv='nx-mv'
alias cp='nx-cp'
```

After editing, reload your shell config:

```bash
# Fish
source ~/.config/fish/config.fish

# Bash
source ~/.bashrc

# Zsh
source ~/.zshrc
```

---

## Usage

Once aliased, usage is identical to the standard commands:

```bash
mv source destination
cp -r source destination
```

The tools print which logical CPU cores are active before executing, so you can verify the pinning at any time.

---

## Requirements

- Linux with `/sys/devices/system/cpu/` topology exposed (standard on all modern kernels)
- `taskset` - part of the `util-linux` package, available by default on all major distributions

---

## TO Do
When I have more time to spare, I think I might add:
- [ ] Progress bar
- [ ] Live transfer speed (MB/s)
- If there is someone who feels like contributing, then all help is welcome, after all, this is to make life with Linux even better for everyone

---

## Part of Nordix

These tools are part of the Nordix/Yggdrasil toolchain.
