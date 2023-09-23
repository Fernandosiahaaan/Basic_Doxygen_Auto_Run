#include <Arduino.h>
#include <ArduinoJson.h>

const int JSON_CAPACITY = 1024;  // Size Max Json want to parse
StaticJsonDocument<JSON_CAPACITY> jsonDoc;
const char tagProject[] = "Json";

/**
 * @brief Scan and Parser data json
 * @param inputJson input of json data will parse (Example = {"name":"FSS","age":25,"city":"Jakarta"})
 */
void jsonScan(String inputJson) {
    // Parse data JSON
    DeserializationError error = deserializeJson(jsonDoc, inputJson);

    // Check if deserialize success
    if (error) {
        ESP_LOGI(tagProject, "Gagal mem-parsing JSON");
    } else {
        // Show key and value in JSON
        ESP_LOGI(tagProject, "Parsing JSON berhasil!");
        for (JsonPair kv : jsonDoc.as<JsonObject>()) {
            const char* key = kv.key().c_str();
            String value = kv.value().as<String>();
            ESP_LOGI(tagProject, "%s : %s ", key, value);
        }
    }
}

/**
 * @brief First init for all device.
 */
void setup() {
    Serial.begin(115200);
}

/**
 * @brief Main Function of this code.
 */
void loop() {
    ESP_LOGI(tagProject, "Masukkan data JSON:");
    // Waiting input data
    while (!Serial.available()) {
        delay(100);
    }
    // Read json input
    String jsonString = Serial.readStringUntil('\n');
    ESP_LOGI(tagProject, "Input JSON = %S", jsonString);
    jsonScan(jsonString);
    delay(5e4);  // 5 seconds
}
