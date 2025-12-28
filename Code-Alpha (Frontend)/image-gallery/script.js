let currentIndex = 0;
const images = document.querySelectorAll('.gallery img');

function openLightbox(img) {
    document.getElementById('lightbox').style.display = 'flex';
    document.getElementById('lightbox-img').src = img.src;
    currentIndex = Array.from(images).indexOf(img);
}

function closeLightbox() {
    document.getElementById('lightbox').style.display = 'none';
}

function changeImage(step) {
    currentIndex = (currentIndex + step + images.length) % images.length;
    document.getElementById('lightbox-img').src = images[currentIndex].src;
}
