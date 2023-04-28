#include <gtkmm.h>
import borealis.window;

int main(int argc, char **argv) {
    auto app = Gtk::Application::create("com.rutins.Borealis");
    return app->make_window_and_run<Window>(argc, argv);
}