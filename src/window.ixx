module;
#include <string>
#include <cassert>
#include <gtkmm.h>
#include <glibmm.h>
#include <giomm.h>

export module borealis.window;

import borealis.util.uri;

using namespace std;
using namespace Gtk;

export class Window : public Gtk::Window {
public:
    Window() {
        set_title("Basic Application");
        set_default_size(800, 600);

        auto bgSettings = Gio::Settings::create("org.gnome.desktop.background");
        auto pictureURI = bgSettings->get_string("picture-uri-dark");
        string_view filename = URI(string_view(pictureURI.c_str())).getPath();
        auto pixbuf = Gdk::Pixbuf::create_from_file(string(filename));
        auto picture = make_managed<Picture>(pixbuf);

        auto overlay = make_managed<Overlay>();
        overlay->set_child(*picture);

        set_child(*overlay);
    }
};