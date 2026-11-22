# Lumiose Online — ZA Launcher (Windows)

The PC launcher for **Lumiose Online**, the fan-made multiplayer mod for Pokémon Legends: Z-A, running on ZA Recomp.

## Download

**[Get the latest release](https://github.com/flakRatty3/ZA-Launcher/releases/latest)**, then download `ZA-Recomp-windows.zip`.

## Install

1. Extract the complete **ZA Recomp** folder somewhere you can write to (not inside OneDrive or Program Files).
2. Open **Lumiose Online.exe**.
3. Choose **all three** of your own Pokémon Legends: Z-A packages together: the base game, **the 2.0.2 update** and the DLC.
   No game files come with this launcher.

**Lumiose Online needs the 2.0.2 update.** ZA Recomp alone also runs the base game (1.0.0) and 2.0.0, so setting up without the
update works until Lumiose prepares, which then fails with **"Update preparation failed: Isolated startup reported a crash"** /
"Lumiose preparation did not finish" (v0.1.38.2 and newer say what is wrong instead). To fix it: close the launcher, delete or
rename the `extracted` folder inside ZA Recomp, open Lumiose Online.exe again and choose the base game, the 2.0.2 update and the
DLC together. Your saves stay.

Older CPUs without AVX2 work from v0.1.38.1 on (the game code is built for them; it runs slower).

**Updating an existing install:** close the game, then copy the complete new archive over your install, merging folders. Your
saves, settings, locally generated game code and installed mod data stay. Launchers up to v0.1.38.2 look for updates at the old
GitHub page, which is gone, so **Update now** inside the launcher will not find new versions. Get new versions from the
releases here.

Controls, settings and troubleshooting: see `READ ME - Lumiose Online.md` and `docs/`.

## What is in this repository

The source and text files that ship inside the release:

| Folder | What it is |
|---|---|
| `runtime/` | the C / C++ / Objective-C runtime the recompiled game runs on |
| `tools/` | the Python tools the launcher runs (game import, patches, Lumiose Online setup and updates) |
| `gamelib-src/` | the templates the game library is generated from on your PC |
| `docs/` | PC controls and mod-update notes |
| `THIRD-PARTY-NOTICES/`, `*LICENSE*` | licenses of the launcher and of every third-party component |

The release zip holds the binaries (the launcher, its runtime DLLs, the bundled Python and toolchain). The build sources of
`lasrecomp.exe` itself were never published with the releases, so they are not here.

## Credits and licenses

- **LAS Recomp** by Peiikai: MIT License (`LICENSE`, `ZA-Recomp-LICENSE.txt`).
- The ZA Recomp port with Lumiose Online integration was first published at `TheMagnumChad/PokeZ-ARecomp-Online`. These releases
  re-host that launcher, under the same licenses, after that page went offline.
- Third-party components keep their own licenses: see `THIRD-PARTY-NOTICES/` and the license files at the top level.

Lumiose Online is not affiliated with Nintendo, The Pokémon Company or Game Freak. This repository and its releases contain no
game files, extracted game assets, generated game code, saves or keys.

## Support

Report bugs in the Lumiose Online Discord (link on [lumioseonline.site](https://lumioseonline.site)), with the screen, what you did
and the log file.
