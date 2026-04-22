/**
 * 실시간 시계 & 날씨 대시보드 - JavaScript
 * 
 * 이 파일이 하는 일:
 * 1. 매초 시계를 업데이트
 * 2. 도시를 검색하면 좌표를 가져옴 (Geocoding)
 * 3. 좌표로 날씨 데이터를 가져옴
 * 4. 날씨에 따라 배경 색상 변경
 */

// ============================================
// 1. 실시간 시계
// ============================================

/** 시계를 업데이트하는 함수 — 매초 호출됨 */
function updateClock() {
    const now = new Date();

    // 시:분:초 포맷
    const hours = String(now.getHours()).padStart(2, '0');
    const minutes = String(now.getMinutes()).padStart(2, '0');
    const seconds = String(now.getSeconds()).padStart(2, '0');
    document.getElementById('clock-time').textContent = `${hours}:${minutes}:${seconds}`;

    // 날짜 포맷 (한국어)
    const dayNames = ['일요일', '월요일', '화요일', '수요일', '목요일', '금요일', '토요일'];
    const year = now.getFullYear();
    const month = now.getMonth() + 1;  // getMonth()는 0부터 시작
    const date = now.getDate();
    const dayName = dayNames[now.getDay()];
    document.getElementById('clock-date').textContent = `${year}년 ${month}월 ${date}일 ${dayName}`;

    // 초 프로그레스 바 (60초 기준 진행률)
    const secondsPercent = (now.getSeconds() / 60) * 100;
    document.getElementById('seconds-fill').style.width = `${secondsPercent}%`;
}

// 1초마다 시계 업데이트
setInterval(updateClock, 1000);
// 페이지 로딩 시 즉시 1회 실행
updateClock();


// ============================================
// 2. 도시 검색 (Geocoding)
// ============================================

const cityInput = document.getElementById('city-input');
const searchBtn = document.getElementById('search-btn');
const searchResults = document.getElementById('search-results');

/** 도시 이름으로 좌표를 검색하는 함수 */
async function searchCity(cityName) {
    if (!cityName.trim()) return;

    showLoading(true);
    hideError();
    searchResults.classList.add('hidden');

    try {
        // Java 백엔드의 /api/geocode 호출
        const response = await fetch(`/api/geocode?city=${encodeURIComponent(cityName)}`);
        const data = await response.json();

        // 북한(KP) 결과 제외
        if (data.results) {
            data.results = data.results.filter(city => city.country_code !== 'KP');
        }

        if (!data.results || data.results.length === 0) {
            showError('도시를 찾을 수 없습니다. 다른 이름으로 검색해보세요.');
            showLoading(false);
            return;
        }

        // 결과가 1개면 바로 날씨 조회
        if (data.results.length === 1) {
            const city = data.results[0];
            await fetchWeather(city.latitude, city.longitude, city.name, city.country);
            showLoading(false);
            return;
        }

        // 결과가 여러 개면 드롭다운으로 보여주기
        displaySearchResults(data.results);
        showLoading(false);

    } catch (error) {
        console.error('검색 오류:', error);
        showError('검색 중 오류가 발생했습니다. 잠시 후 다시 시도해주세요.');
        showLoading(false);
    }
}

/** 검색 결과를 드롭다운에 표시 */
function displaySearchResults(results) {
    searchResults.innerHTML = '';
    results.forEach(city => {
        const li = document.createElement('li');
        li.innerHTML = `
            <span>📍 ${city.name}</span>
            <span class="result-country">${city.admin1 || ''} ${city.country || ''}</span>
        `;
        li.addEventListener('click', async () => {
            searchResults.classList.add('hidden');
            cityInput.value = city.name;
            showLoading(true);
            await fetchWeather(city.latitude, city.longitude, city.name, city.country);
            showLoading(false);
        });
        searchResults.appendChild(li);
    });
    searchResults.classList.remove('hidden');
}

// 검색 버튼 클릭
searchBtn.addEventListener('click', () => searchCity(cityInput.value));

// Enter 키로 검색
cityInput.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') searchCity(cityInput.value);
});


// ============================================
// 3. 날씨 데이터 가져오기
// ============================================

/** 좌표로 날씨 정보를 가져오는 함수 */
async function fetchWeather(lat, lon, cityName, country) {
    hideError();

    try {
        // Java 백엔드의 /api/weather 호출
        const response = await fetch(`/api/weather?lat=${lat}&lon=${lon}`);
        const data = await response.json();

        // 화면에 표시
        displayCurrentWeather(data, cityName, country);
        displayForecast(data);

        // 날씨에 따라 배경 변경
        changeBackground(data.current.weather_code);

    } catch (error) {
        console.error('날씨 조회 오류:', error);
        showError('날씨 정보를 가져올 수 없습니다.');
    }
}

/** 현재 날씨를 화면에 표시 */
function displayCurrentWeather(data, cityName, country) {
    const current = data.current;
    const daily = data.daily;

    // 위치
    document.getElementById('location-name').textContent = 
        country ? `${cityName}, ${country}` : cityName;

    // 온도
    document.getElementById('temp-value').textContent = Math.round(current.temperature_2m);

    // 날씨 아이콘 & 설명
    const weatherInfo = getWeatherInfo(current.weather_code);
    document.getElementById('weather-icon-large').textContent = weatherInfo.icon;
    document.getElementById('weather-desc').textContent = weatherInfo.description;

    // 체감 온도
    document.getElementById('feels-like').textContent = 
        `체감 ${Math.round(current.apparent_temperature)}°C`;

    // 상세 정보
    document.getElementById('humidity').textContent = `${current.relative_humidity_2m}%`;
    document.getElementById('wind-speed').textContent = `${current.wind_speed_10m} km/h`;

    // 최고/최저 (오늘)
    if (daily) {
        document.getElementById('temp-max').textContent = `${Math.round(daily.temperature_2m_max[0])}°C`;
        document.getElementById('temp-min').textContent = `${Math.round(daily.temperature_2m_min[0])}°C`;
    }

    // 날씨 섹션 보이기 (애니메이션)
    const weatherSection = document.getElementById('weather-section');
    weatherSection.classList.remove('hidden');
    weatherSection.classList.add('fade-in-up');
}

/** 5일 예보를 화면에 표시 */
function displayForecast(data) {
    if (!data.daily) return;

    const grid = document.getElementById('forecast-grid');
    grid.innerHTML = '';

    const daily = data.daily;
    const dayNames = ['일', '월', '화', '수', '목', '금', '토'];

    // 내일부터 5일 (today index=0 이므로 1부터)
    const count = Math.min(daily.time.length, 5);
    for (let i = 0; i < count; i++) {
        const date = new Date(daily.time[i]);
        const dayName = i === 0 ? '오늘' : dayNames[date.getDay()];
        const weatherInfo = getWeatherInfo(daily.weather_code[i]);

        const dayEl = document.createElement('div');
        dayEl.className = 'forecast-day';
        dayEl.innerHTML = `
            <span class="day-name">${dayName}</span>
            <span class="day-icon">${weatherInfo.icon}</span>
            <span class="day-temp-high">${Math.round(daily.temperature_2m_max[i])}°</span>
            <span class="day-temp-low">${Math.round(daily.temperature_2m_min[i])}°</span>
        `;
        grid.appendChild(dayEl);
    }

    // 예보 섹션 보이기
    const forecastSection = document.getElementById('forecast-section');
    forecastSection.classList.remove('hidden');
    forecastSection.classList.add('fade-in-up');
}


// ============================================
// 4. 날씨 코드 → 아이콘 & 설명 매핑
// ============================================

/**
 * WMO 날씨 코드를 아이콘과 한국어 설명으로 변환
 * 참고: https://open-meteo.com/en/docs#weathervariables
 */
function getWeatherInfo(code) {
    const weatherMap = {
        0:  { icon: '☀️', description: '맑음', bg: 'clear' },
        1:  { icon: '🌤️', description: '대체로 맑음', bg: 'clear' },
        2:  { icon: '⛅', description: '부분적으로 흐림', bg: 'cloudy' },
        3:  { icon: '☁️', description: '흐림', bg: 'cloudy' },
        45: { icon: '🌫️', description: '안개', bg: 'fog' },
        48: { icon: '🌫️', description: '짙은 안개', bg: 'fog' },
        51: { icon: '🌦️', description: '가벼운 이슬비', bg: 'rain' },
        53: { icon: '🌦️', description: '이슬비', bg: 'rain' },
        55: { icon: '🌧️', description: '강한 이슬비', bg: 'rain' },
        56: { icon: '🌧️', description: '얼어붙는 이슬비', bg: 'rain' },
        57: { icon: '🌧️', description: '강한 얼어붙는 이슬비', bg: 'rain' },
        61: { icon: '🌧️', description: '가벼운 비', bg: 'rain' },
        63: { icon: '🌧️', description: '비', bg: 'rain' },
        65: { icon: '🌧️', description: '강한 비', bg: 'rain' },
        66: { icon: '🌧️', description: '얼어붙는 비', bg: 'rain' },
        67: { icon: '🌧️', description: '강한 얼어붙는 비', bg: 'rain' },
        71: { icon: '🌨️', description: '가벼운 눈', bg: 'snow' },
        73: { icon: '🌨️', description: '눈', bg: 'snow' },
        75: { icon: '❄️', description: '강한 눈', bg: 'snow' },
        77: { icon: '❄️', description: '싸락눈', bg: 'snow' },
        80: { icon: '🌦️', description: '가벼운 소나기', bg: 'rain' },
        81: { icon: '🌧️', description: '소나기', bg: 'rain' },
        82: { icon: '⛈️', description: '강한 소나기', bg: 'storm' },
        85: { icon: '🌨️', description: '가벼운 눈 소나기', bg: 'snow' },
        86: { icon: '🌨️', description: '강한 눈 소나기', bg: 'snow' },
        95: { icon: '⛈️', description: '뇌우', bg: 'storm' },
        96: { icon: '⛈️', description: '가벼운 우박 뇌우', bg: 'storm' },
        99: { icon: '⛈️', description: '강한 우박 뇌우', bg: 'storm' },
    };

    return weatherMap[code] || { icon: '🌈', description: '알 수 없음', bg: 'clear' };
}


// ============================================
// 5. 날씨별 배경 변경
// ============================================

/** 날씨 상태에 따라 배경 그라데이션을 변경 */
function changeBackground(weatherCode) {
    const info = getWeatherInfo(weatherCode);
    const root = document.documentElement;

    const backgrounds = {
        clear:  ['#0f0c29', '#302b63', '#24243e'],    // 보라색 밤하늘
        cloudy: ['#283048', '#414f6b', '#859398'],     // 회색빛 하늘
        fog:    ['#3e3e3e', '#5c5c5c', '#787878'],     // 안개 느낌
        rain:   ['#0f2027', '#203a43', '#2c5364'],     // 어두운 파랑
        snow:   ['#2c3e50', '#4ca1af', '#c9d6ff'],     // 차가운 파랑
        storm:  ['#1a1a2e', '#16213e', '#0f3460'],     // 어두운 남색
    };

    const colors = backgrounds[info.bg] || backgrounds.clear;
    root.style.setProperty('--bg-gradient-1', colors[0]);
    root.style.setProperty('--bg-gradient-2', colors[1]);
    root.style.setProperty('--bg-gradient-3', colors[2]);
}


// ============================================
// 6. UI 유틸리티 함수
// ============================================

function showLoading(show) {
    document.getElementById('loading').classList.toggle('hidden', !show);
}

function showError(message) {
    const errorEl = document.getElementById('error-msg');
    document.getElementById('error-text').textContent = message;
    errorEl.classList.remove('hidden');
}

function hideError() {
    document.getElementById('error-msg').classList.add('hidden');
}


// ============================================
// 7. 초기 로딩: 서울 날씨를 기본으로 표시
// ============================================

window.addEventListener('DOMContentLoaded', async () => {
    // 서울의 좌표 (기본값)
    const defaultLat = 37.5665;
    const defaultLon = 126.9780;

    try {
        showLoading(true);
        await fetchWeather(defaultLat, defaultLon, '서울', '대한민국');
    } catch (error) {
        console.error('초기 로딩 오류:', error);
    } finally {
        showLoading(false);
    }
});
