#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

int run_oled_reinit(const struct zmk_behavior_binding *binding, const struct zmk_behavior_binding_event *event) {
    LOG_INF("Reinitializing OLED...");
    int result = zmk_display_init();
    if (result < 0) {
        LOG_ERR("Failed to reinitialize OLED: %d", result);
        return result;
    }
    return 0;
}

static const struct behavior_driver_api oled_reinit_driver_api = {
    .binding_pressed = run_oled_reinit,
};

DEVICE_DT_INST_DEFINE(0, NULL, NULL, NULL, NULL, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, &oled_reinit_driver_api);
