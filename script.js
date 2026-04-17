// User data
const users = {
  parth: { password: 'parth', data: [] },
  shravan: { password: 'shravan', data: [] },
  manas: { password: 'manas', data: [] },
  aashka: { password: 'aashka', data: [] },
  diksha: { password: 'diksha', data: [] }
};

let currentUser = null, lastFare = 0, distanceLeft = 5, interval;

// DOM references
const loginModal = document.getElementById('loginModal');
const username = document.getElementById('username');
const password = document.getElementById('password');
const loginBtn = document.getElementById('loginBtn');
const logoutBtn = document.getElementById('logoutBtn');
const statusText = document.getElementById('statusText');
const loginError = document.getElementById('loginError');

const fromStop = document.getElementById('fromStop');
const toStop = document.getElementById('toStop');
const busType = document.getElementById('busType');
const fareResult = document.getElementById('fareResult');
const bookingStatus = document.getElementById('bookingStatus');

const historyTable = document.getElementById('historyTable');
const txnTable = document.getElementById('txnTable');

const busNo = document.getElementById('busNo');
const routeName = document.getElementById('routeName');
const distance = document.getElementById('distance');
const eta = document.getElementById('eta');
const trackingStatus = document.getElementById('trackingStatus');

// Show login modal
function showLogin() {
  loginModal.style.display = 'block';
  loginError.style.display = 'none';
  username.focus();
}

// Close modal by clicking outside
function closeModal(e) {
  if (e.target === loginModal) loginModal.style.display = 'none';
}

// Login logic
function login() {
  const u = username.value.toLowerCase().trim();
  const p = password.value.trim();

  if (users[u] && users[u].password === p) {
    currentUser = u;
    loginModal.style.display = 'none';
    loginBtn.style.display = 'none';
    logoutBtn.style.display = 'inline';
    statusText.innerText = 'Welcome, ' + u;
    username.value = '';
    password.value = '';
    loginError.style.display = 'none';
    loadUserData();
  } else {
    loginError.style.display = 'block';
  }
}

// Logout logic
function logout() {
  currentUser = null;
  loginBtn.style.display = 'inline';
  logoutBtn.style.display = 'none';
  statusText.innerText = 'Login to continue';
  historyTable.innerHTML = '';
  txnTable.innerHTML = '';
  busNo.innerText = '--';
  routeName.innerText = '--';
  distance.innerText = '--';
  eta.innerText = '--';
  trackingStatus.innerText = 'Login to start tracking';
  clearInterval(interval);
}

// Show section
function showSection(id) {
  ['home', 'bus', 'history', 'transactions'].forEach(s => {
    document.getElementById(s).style.display = 'none';
  });
  document.getElementById(id).style.display = 'block';
}

// Calculate fare
function calculateFare() {
  if (!currentUser) return alert('Login first');
  let fare = 10;
  if (busType.value === 'Express') fare += 10;
  if (busType.value === 'AC') fare += 20;
  fare += Math.floor(Math.random() * 10);
  fareResult.innerText = 'Fare: ₹' + fare;
  lastFare = fare;
}

// Book ticket
function bookTicket() {
  if (!currentUser) return alert('Login first');
  if (!lastFare) return alert('Calculate fare first');

  let t = {
    date: new Date().toLocaleDateString(),
    route: `${fromStop.value} → ${toStop.value}`,
    bus: busType.value,
    fare: '₹' + lastFare
  };

  users[currentUser].data.push(t);
  bookingStatus.innerText = 'Ticket Booked';
  fareResult.innerText = '';
  lastFare = 0;
  loadUserData();
}

// Load user data
function loadUserData() {
  historyTable.innerHTML = '';
  txnTable.innerHTML = '';
  users[currentUser].data.forEach(d => {
    historyTable.innerHTML += `<tr><td>${d.date}</td><td>${d.route}</td><td>${d.bus}</td><td>${d.fare}</td></tr>`;
    txnTable.innerHTML += `<tr><td>${d.date}</td><td>${d.route}</td><td>${d.fare}</td></tr>`;
  });

  if (users[currentUser].data.length > 0) {
    const last = users[currentUser].data[users[currentUser].data.length - 1];
    busNo.innerText = last.bus;
    routeName.innerText = last.route;
    trackingStatus.innerText = 'Click Start Tracking to simulate live bus';
  } else {
    busNo.innerText = '--';
    routeName.innerText = '--';
    trackingStatus.innerText = 'No trips yet';
  }
}

const buses = {
  '42A': { route: 'City → Campus', fare: 20, seats: Array(16).fill(false) },
  '18B': { route: 'Railway → Campus', fare: 25, seats: Array(16).fill(false) },
  '12C': { route: 'Market → Campus', fare: 15, seats: Array(16).fill(false) },
  '55D': { route: 'City → Market', fare: 30, seats: Array(16).fill(false) }
};



// Start live tracking simulation
function startTracking() {
  if (!currentUser) return alert('Login first');
  distanceLeft = 5;
  clearInterval(interval);
  trackingStatus.innerText = 'Tracking started...';
  interval = setInterval(() => {
    if (distanceLeft > 0) {
      distanceLeft -= 0.5;
      distance.innerText = distanceLeft.toFixed(1);
      eta.innerText = Math.ceil(distanceLeft * 2);
    } else {
      trackingStatus.innerText = 'Bus has arrived at your stop';
      clearInterval(interval);
      distance.innerText = '0';
      eta.innerText = '0';
    }
  }, 2000);
}
