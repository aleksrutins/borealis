/* MIT License
 *
 * Copyright (c) 2023 Aleks Rutins
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * SPDX-License-Identifier: MIT
 */

#include "config.h"

#include "borealis-window.h"

struct _BorealisWindow
{
	AdwApplicationWindow  parent_instance;

	/* Template widgets */
};

G_DEFINE_FINAL_TYPE (BorealisWindow, borealis_window, ADW_TYPE_APPLICATION_WINDOW)

static GFile *
get_bg_file(BorealisWindow *self, GtkPicture *picture) {
        g_autoptr (GSettings) bg_settings = g_settings_new ("org.gnome.desktop.background");
        char                 *bg = g_settings_get_string (bg_settings, "picture-uri-dark");
        GFile *file = g_file_new_for_uri (bg);
        gtk_picture_set_file (picture, file);
        return file;
}

static void
borealis_window_class_init (BorealisWindowClass *klass)
{
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

	gtk_widget_class_set_template_from_resource (widget_class, "/com/rutins/Borealis/borealis-window.ui");
        gtk_widget_class_bind_template_callback (widget_class, get_bg_file);
}

static void
borealis_window_init (BorealisWindow *self)
{
	gtk_widget_init_template (GTK_WIDGET (self));
}
