#include "DHT.h"

// Chọn chân kết nối
#define DHTPIN 4       // GPIO4 (có thể đổi sang chân bạn dùng)
#define DHTTYPE DHT11  // Loại cảm biến: DHT11 hoặc DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("Bắt đầu đọc dữ liệu từ DHT11...");
  dht.begin();
}

void loop() {
  // DHT11 đọc khá chậm, nên cần delay ít nhất 2 giây giữa các lần đọc
  delay(2000);

  // Đọc độ ẩm (%)
  float h = dht.readHumidity();
  // Đọc nhiệt độ (°C)
  float t = dht.readTemperature();

  // Kiểm tra lỗi đọc
  if (isnan(h) || isnan(t)) {
    Serial.println("❌ Lỗi đọc dữ liệu từ DHT11!");
    return;
  }

  Serial.print("Độ ẩm: ");
  Serial.print(h);
  Serial.print(" %\t");

  Serial.print("Nhiệt độ: ");
  Serial.print(t);
  Serial.println(" °C");
}