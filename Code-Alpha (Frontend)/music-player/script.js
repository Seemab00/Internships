const audio = document.getElementById('audio');
const title = document.getElementById('title');
const artist = document.getElementById('artist');
const progress = document.getElementById('progress');

const playlist = [
    { title: 'Song 1', artist: 'Artist 1', src: 'song1.mp3' },
    { title: 'Song 2', artist: 'Artist 2', src: 'song2.mp3' }
];
let current = 0;

function loadSong() {
    title.textContent = playlist[current].title;
    artist.textContent = playlist[current].artist;
    audio.src = playlist[current].src;
    audio.load();
}

function playPause() {
    audio.paused ? audio.play() : audio.pause();
}

function prev() { current = (current - 1 + playlist.length) % playlist.length; loadSong(); audio.play(); }
function next() { current = (current + 1) % playlist.length; loadSong(); audio.play(); }

function seek(value) { audio.currentTime = (value / 100) * audio.duration; }
function setVolume(value) { audio.volume = value; }

audio.addEventListener('timeupdate', () => {
    progress.value = (audio.currentTime / audio.duration) * 100;
});

loadSong(); 