package com.edward.weather_dashboard.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;
import java.net.URI;
import java.net.URLEncoder;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.nio.charset.StandardCharsets;

/**
 * 날씨 API 프록시 컨트롤러
 * 
 * 프론트엔드에서 직접 외부 API를 호출하면 CORS 문제가 발생할 수 있으므로,
 * 이 컨트롤러가 중간에서 Open-Meteo API를 대신 호출합니다.
 */
@RestController
@RequestMapping("/api")
public class WeatherController {

    // Java 11+에서 제공하는 HttpClient — 외부 API 호출에 사용
    private final HttpClient httpClient = HttpClient.newHttpClient();

    /**
     * 현재 날씨 조회 API
     * 
     * 사용법: GET /api/weather?lat=37.57&lon=126.98
     * 
     * @param lat 위도
     * @param lon 경도
     * @return Open-Meteo에서 받은 날씨 JSON 데이터
     */
    @GetMapping("/weather")
    public String getWeather(
            @RequestParam("lat") double lat,
            @RequestParam("lon") double lon) throws IOException, InterruptedException {

        // Open-Meteo API URL 구성
        String url = String.format(
            "https://api.open-meteo.com/v1/forecast?" +
            "latitude=%.4f&longitude=%.4f" +
            "&current=temperature_2m,relative_humidity_2m,weather_code,wind_speed_10m,apparent_temperature" +
            "&daily=temperature_2m_max,temperature_2m_min,weather_code" +
            "&timezone=Asia%%2FSeoul" +
            "&forecast_days=5",
            lat, lon
        );

        // HTTP GET 요청 생성
        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(url))
                .GET()
                .build();

        // 요청 보내고 응답 받기
        HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());

        return response.body();
    }

    /**
     * 도시 검색 (Geocoding) API
     * 
     * 사용법: GET /api/geocode?city=서울
     * 
     * @param city 검색할 도시 이름
     * @return 도시 목록 (위도, 경도 포함) JSON
     */
    @GetMapping("/geocode")
    public String geocode(@RequestParam("city") String city) throws IOException, InterruptedException {

        // 도시명을 URL 인코딩 (한글 지원)
        String encodedCity = URLEncoder.encode(city, StandardCharsets.UTF_8);

        String url = String.format(
            "https://geocoding-api.open-meteo.com/v1/search?name=%s&count=5&language=ko",
            encodedCity
        );

        HttpRequest request = HttpRequest.newBuilder()
                .uri(URI.create(url))
                .GET()
                .build();

        HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());

        return response.body();
    }
}
