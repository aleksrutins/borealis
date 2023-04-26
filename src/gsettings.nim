import std/[os]
import std/strutils as strutils
{.passl: strutils.strip(gorge("pkg-config --libs gio-2.0")).}

type
    GSettings* = distinct pointer

{.push importc, cdecl.}

proc g_settings_new*(schema_id: cstring): GSettings
proc g_settings_get_string*(settings: GSettings, key: cstring): cstring