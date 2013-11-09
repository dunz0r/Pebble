#include "pebble_os.h"
#include "pebble_app.h"
#include "pebble_fonts.h"


#define MY_UUID { 0x22, 0x19, 0x1A, 0x3B, 0x20, 0x2B, 0x47, 0x58, 0xA4, 0xB4, 0x5F, 0x9F, 0x9D, 0xE0, 0xF9, 0x8E }
PBL_APP_INFO(MY_UUID,
             "Hello World", "Acme Company",
             1, 0, /* App version */
             DEFAULT_MENU_ICON,
             APP_INFO_STANDARD_APP);

Window window;
TextLayer hello_layer;


void handle_init(AppContextRef ctx) {

  window_init(&window, "Window Name");
  window_stack_push(&window, true /* Animated */);
  text_layer_init(&hello_layer, GRect(0,65,144,30));
  text_layer_set_text_alignment(&hello_layer,GTextAlignmentCenter);
  text_layer_set_text(&hello_layer, time());
  text_layer_set_font(&hello_layer, fonts_get_system_font(FONT_KEY_ROBOTO_CONDENSED_21));
  layer_add_child(&window.layer, &hello_layer.layer);
}


void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init
  };
  app_event_loop(params, &handlers);
}
