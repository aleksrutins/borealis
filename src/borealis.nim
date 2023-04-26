import std/uri
import owlkettle
import owlkettle/adw
import gsettings

viewable App:
  bgPixbuf: Pixbuf

  hooks:
    beforeBuild:
      let settings = g_settings_new("org.gnome.desktop.background")
      let bg = parseUri($g_settings_get_string(settings, "picture-uri-dark")).path
      state.bgPixbuf = loadPixbuf(bg)

method view(app: AppState): Widget =
  result = gui:
    Window:
      title = "Borealis"

      Overlay:
        if app.bgPixbuf.isNil:
          Label(text = "")
        else:
          Picture:
            pixbuf = app.bgPixbuf
      
adw.brew(gui(App()))