/* testapplication-window.c
 *
 * Copyright 2024 kuso4ek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "config.h"

#include "testapplication-window.h"

struct _TestapplicationWindow
{
    AdwApplicationWindow  parent_instance;

    /* Template widgets */
    AdwHeaderBar* header_bar;
    GtkLabel* label;
    GtkEntry* entry;
    GtkButton* done, *exit;
};

G_DEFINE_FINAL_TYPE(TestapplicationWindow, testapplication_window, ADW_TYPE_APPLICATION_WINDOW)

static void Done(GtkButton* button, TestapplicationWindow* win)
{
    gtk_label_set_label(win->label, gtk_entry_buffer_get_text(gtk_entry_get_buffer(win->entry)));
}

static void Exit(GtkButton* button, AdwApplicationWindow* win)
{
    gtk_window_destroy(GTK_WINDOW(win));
}

static void testapplication_window_class_init(TestapplicationWindowClass *winClass)
{
    GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(winClass);

    gtk_widget_class_set_template_from_resource(widget_class, "/org/IDN/TestApplication/testapplication-window.ui");

    gtk_widget_class_bind_template_child(widget_class, TestapplicationWindow, header_bar);
    gtk_widget_class_bind_template_child(widget_class, TestapplicationWindow, label);
    gtk_widget_class_bind_template_child(widget_class, TestapplicationWindow, entry);
    gtk_widget_class_bind_template_child(widget_class, TestapplicationWindow, done);
    gtk_widget_class_bind_template_child(widget_class, TestapplicationWindow, exit);

    //gtk_widget_class_bind_template_callback_full(widget_class, "Done", G_CALLBACK(Done));
}

static void testapplication_window_init(TestapplicationWindow *self)
{
    gtk_widget_init_template(GTK_WIDGET(self));

    g_signal_connect(self->done, "clicked", G_CALLBACK(Done), self);
    g_signal_connect(self->exit, "clicked", G_CALLBACK(Exit), &self->parent_instance);
}

