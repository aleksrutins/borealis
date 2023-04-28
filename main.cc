#include <memory>
#include <gtkmm.h>
#include <adwaita.h>
#include <gtkmm/init.h>
#include "window.hh"

using namespace std;
using namespace borealis;

int main(int argc, char **argv) {
    //Gtk::init_gtkmm_internals();
    //adw_init();
    //auto app = shared_ptr<Gtk::Application>(reinterpret_cast<Gtk::Application*>(Glib::wrap_auto(G_OBJECT(adw_application_new("com.rutins.Borealis", G_APPLICATION_DEFAULT_FLAGS)))));
    auto app = Gtk::Application::create("com.rutins.Borealis");
    return app->make_window_and_run<Window>(argc, argv);
}