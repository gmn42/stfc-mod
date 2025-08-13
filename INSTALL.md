# Star Trek Fleet Command - Community Mod

<p align="center">
  <img src="https://img.shields.io/badge/License-GPLv3-blue.svg" alt="License: GPLv3">
  <img src="https://img.shields.io/github/sponsors/netniv" alt="Sponsorship">
</p>

<p align="center">
   A community mod (patch) for PC and Mac that adds a couple of tweaks to the <b>Star Trek Fleet Command&#8482;</b> game
</p>

## Downloads / Releases

The STFC Community Mod is available on GitHub.

You can download either the [latest official release](https://github.com/netniv/stfc-mod/releases/latest/) or any other release, including [alpha/beta](https://github.com/netniv/stfc-mod/releases/) builds.

__Notes:__

-  GitHub may require you to login to see the downloads for
   pre-releases and you will need to expand the
   assets section to see the downloads.

- There is no difference between the versioned and unversioned zip
  files. They are simply named this way to allow people to store
  multiple versions rather than overwritting or having a random
  number appended by windows.

## Configuration

__IMPORTANT__: Any desired configuration changes should __ONLY__ be made in the
`community_patch_settings.toml` file.

When the game is launched:

- If the configuration file does not exist, it will be created with default values.  It
  will not have any comments describing these settings.

- The configuration file is read with any missing settings defaulting to predefined values.

- The finalized configuration including any assumed default values are written to
`community_patch_runtime.vars`.

  __NOTE:__ You should NOT make any changes to this file.  This file is
constantly rewritten when the game starts so any modifications to it are never used and will be
lost.

If you have any problems with a setting, check for that setting in the _.vars_ file to verify
that the parse value of that setting was correctly applied.  You may also need to check the
`community_patch.log` file to see if any errors were encountered while parsing the _.toml_ file.

## Installation on Windows

__NOTE:__ The `Star Trek Fleet Command` game itself is located by default at:

- `C:\Games\Star Trek Fleet Command\Star Trek Fleet Command\default\game`

Installation of the Community Mod is a manual process for Windows (or Wine).

1. Download the `stfc-community-patch.zip` file from your chosen [github release](https://github.com/netniv/stfc-mod/releases/) and extract the `version.dll` file.

2. Open the game folder in Explorer.  The default folder for the game also holds the settings file.

   __NOTE:__ If this folder isn't present, or no log files are created when running the game
   see the [Problems Under Windows](#problems-under-windows) section below.

3. Move the extracted `version.dll` file into this folder.

4. Run the game!  If all is well, and one does not already exist, the mod will
   create `community_patch_settings.toml` and populate this with the default
   values.

5. For first time users of the Community Mod, it recommended to utilise the
   [sample configuration file](example_community_patch_settings.toml), which can
   be saved to the game folder with the name `community_patch_settings.toml`.  This
   sample file contains additional comments that explain the available settings.

## Installation on Mac

__NOTE:__ The `Star Trek Fleet Command` game itself is located at:

- `~/Library/Application Support/Star Trek Fleet Command/Games/Star Trek Fleet Command/STFC/default/game`

You should only need to access this folder if you need to view the `community_patch.log` file while troubleshooting a problem.

1. Download the `stfc-community-patch-installer.dmg` file from your chosen
   [github release](https://github.com/netniv/stfc-mod/releases/).

2. Open the DMG, then drag and drop the `Launcher` to your `Applications` folder.  The
   STFC Community Launcher must be used to start the game to have the mod loaded.  If
   you start the game using the games Launcher, you will NOT have the mod loaded.

3. Run the game from the launcher!  If all is well, the mod will create `community_patch_settings.toml`
   in the settings folder `~/Library/Preferences/com.stfcmod.startrekpatch`.

   Note: By default, MacOS hides the `~/Library` folder in Finder, so if it isn't visible,
   see the [Problems Under mac](#problems-under-mac) section below for tips on opening it.

4. For first time users of the Community Mod, it recommended to utilise the
   [sample configuration file](example_community_patch_settings.toml), which can
   be saved to the settings folder with the name `community_patch_settings.toml`.  This
   sample file contains additional comments that explain the available settings.

## Installation on Wine/Linux

__NOTE:__ The `Star Trek Fleet Command` game itself is located at:

- `~/Games/star-trek-fleet-command/drive_c/Games/Star Trek Fleet Command/Star Trek Fleet Command/default/game`.

The Windows version of the mod, and the game itself, run well under Linux using the Wine compatability layer.

If the game is installed using the [Lutris STFC installer](https://lutris.net/games/star-trek-fleet-command/),
the mod can be installed by following the [Windows](#installation-on-windows) directions
above.

If the game is installed through other launchers or directly in an unmanaged WINEPREFIX,
an additional adjustment may be needed for it to load the mod  library correctly; see the
[Problems Under Wine/Linux](#problems-under-winelinux) notes below.

## Common Problems

The most common problems getting the DLL to work are:

1. Not installed in the correct location.  This must be `Game` folder where `prime.exe` also exists.

2. Windows is blocking the DLL.  Right-click the file and select Properties.  On the `General` tab
   there will be additional text at the bottom:

   ```console
   This file can from another
   computer and might be blocked to
   help protect this computer
   ```

   To the right of this, there will be a tick box called `Unblock`.  Tick the box and then click OK
   to unblock the file.

3. The configuration file has the wrong name (see above)

4. The configuration file is not being parsed as you expect which is normally because:

   - Your configuration isn't being parsed
   - The configuration option name is spelt wrong
   - The configuration option name is in the wrong section
   - The configuration option value is not a true or false

   You can verify your configuration by looking at `community_patch_runtime.vars` and/or the
   log file `community_patch.log`.

## Problems under Windows

On windows, sometimes the game is installed in a user's profile folder instead of the
default location.  This is happens when the STFC installer finds more than one user
attempted to install it, or if the current user doesn't have admin rights.

If this is the case, to find the correct game location for the `version.dll` file, do the
following:

1. Open Task Manager while the game is running (press Ctrl-Alt-Delete)
2. Right-click `prime.exe` and select 'Expand'
3. Right-click `Star Trek Fleet Command` and select 'Open file location'

An Explorer window will open and you can check for `prime.exe` to verify this is the
correct folder.

__IMPORTANT__: The version.dll file should NOT be placed within the official STFC Launcher's
folder as this will prevent the Launcher from working and the ability to update the game.

## Problems under Mac

MacOS hides the `Library` folder in Finder by default. There are several ways to open it:

- Hold the `⌥ option` key (or `Alt` on a PC keyboard) in __Finder__ and click the __Go to__ menu item
and then click the __Library__ folder item

  or

- Press `⌘ cmd`+`⇧ shift`+`G` in the __Finder__ for the Goto box and type in `~/Library`

  or

- Use __Terminal__ and type: `open ~/Library`

The Community Launcher shows the version of `Star Trek Fleet Command` that was detected
under the current user.  If this shows as `-1`, then the recommended course of action is
to uninstall and reinstall `Star Trek Fleet Command` whcih can be done without needing
to reinstall the Community Mod launcher.

### Problems under Wine/Linux

To use the Windows version of the mod under Wine, the wine DLL override setting for
`version.dll` _must_ be set to `n,b` or it will not be loaded.

When using the [Lutris STFC installer](https://lutris.net/games/star-trek-fleet-command/)
(which is recommended), this override will have already been set by the installer within
the runner configuration.

Otherwise, it can be set in the `winecfg.exe` Libraries tab or by setting the `WINEDLLOVERRIDES` enviroment variable to `version.dll=n,b` before launching the game.

If the game folder does not exist in the default location mentioned under [Installation on Wine/Linux](#installation-on-winelinux), it may exist under:

- `drive_c/Games/Star Trek Fleet Command/Star Trek Fleet Command/default/game`

__NOTE:__ This is a relative path that starts at the wine environment (WINEPREFIX).
