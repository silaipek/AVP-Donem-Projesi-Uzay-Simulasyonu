#include <stdio.h>
#include <math.h>

#define PI 3.14159265


// Gezegen isimleri ve yercekimi ivmelerini global dizilerde tutuyoruz.

const char *gezegenler[] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};
double yercekimi_ivmeleri[] = {3.70, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};

//Deneydeki Fonksiyonlar

// Serbest dusme mesafesini hesaplar.
void serbest_dusme(double *g, double *t) {
    printf("\n - Serbest Dusme Deneyi Sonuclari -\n");
    for(int i=0; i<8; i++) {
        double sonuc = 0.5 * (*(g + i)) * (*t) * (*t);   // h = 1/2 * g * t^2 formulunden
        printf("Cisim %s gezegeninde %.2f saniye boyunca %.2f metre yol (h) kat etmistir.\n", *(gezegenler + i),*t,sonuc);
    }
}

//Dusey yukari atista cikilabilecek maksimum yuksekligi hesaplar.
void yukari_atis(double *g, double *v0) {
    printf("\n - Yukari Atis Deneyi Sonuclari -\n");
    for(int i=0; i<8; i++) {
        double sonuc = ((*v0) * (*v0)) / (2 * (*(g + i))); // hmax = v0^2 / 2*g formulunden
        printf("Cismin %s gezegeninde cikabilecegi maksimum yukseklik (h_max)= %.2f metre.\n", *(gezegenler + i), sonuc);
    }
}

// Cismin gezegenlerdeki agirligini hesaplar.
void agirlik_dny(double *g, double *m) {
    printf("\n - Agirlik Deneyi Sonuclari -\n");
    for(int i=0; i<8; i++) {
        double sonuc = (*m) * (*(g + i)); // G = m*g formulunden
        printf("%s gezegeninde cismin agirligi (G)= %.2f Newton\n", *(gezegenler + i), sonuc);
    }
}

//Yercekimi potansiyel enerjisini hesaplar.
void pot_enerji(double *g, double *m, double *h) {
    printf("\n - Kutlecekimsel Potansiyel Enerji Deneyi -\n");
    for(int i=0; i<8; i++) {
        double sonuc = (*m) * (*(g + i)) * (*h); // Ep = m*g*h formulunden
        printf("Cismin %s yuzeyinden %.2f metre yukseklikteyken sahip oldugu potansiyel enerji (Ep)= %.2f Joule\n", *(gezegenler + i),*h, sonuc);
    }
}

//Sivi basincini hesaplar.
void hidro_basinc(double *g, double *rho, double *h) {
    printf("\n - Hidrostatik Basinc Deneyi Sonuclari -\n");
    for(int i=0; i<8; i++) {
        double sonuc = (*rho) * (*(g + i)) * (*h); // P = rho*g*h
        printf("Sivinin %.2f derinlikte %s yuzeyine uyguladigi hidrostatik basinc (P)= %.2f Pascal\n", *h, *(gezegenler + i), sonuc);
    }
}

//Arsimet kaldirma kuvvetini hesaplar.
void arsimentKuv(double *g, double *rho, double *v) {
    printf("\n - Arsimet Kaldirma Kuvveti Deneyi - \n");
    for(int i=0; i<8; i++) {
        double sonuc = (*rho) * (*(g + i)) * (*v); // Fk = rho*g*V formulunden
        printf("%s gezegeninde sivi icerisindeki cisme uygulanan kaldirma kuvveti (Fk)= %.2f Newton\n", *(gezegenler + i), sonuc);
    }
}

//Basit sarkac periyodunu hesaplar.
void basit_sarkac(double *g, double *l) {
    printf("\n - Basit Sarkac Periyodu Deneyi -\n");
    for(int i=0; i<8; i++) {
        double sonuc = 2 * PI * sqrt((*l) / (*(g + i))); // T = 2*PI*sqrt(L/g) formulunden
        printf("%s gezegeninde periyot (T): %.2f saniye\n", *(gezegenler + i), sonuc);
    }
}

//ipteki gerilme kuvvetini hesaplar.
void sbt_ip(double *g, double *m) {
    printf("\n- Sabit Ip Gerilmesi Deneyi -\n");
    for(int i=0; i<8; i++) {
        double sonuc = (*m) * (*(g + i)); // T = m*g formulunden
        printf("Ucunda %.2f kutleli bir cisim asili olan ipin %s gezegeninde ip gerilme kuvveti (T)= %.2f Newton\n",*m, *(gezegenler + i), sonuc);
    }
}

//Asansor icindeki eylemsizlik etkisini hesaplar.
void asansor_dny(double *g, double *m, double *a, int durum) {
    printf("\n - Asansor Deneyi Sonuclari -\n");
    for(int i=0; i<8; i++) {
        double sonuc;
        // Durum 1: Yukari hizlanan / Asagi yavaslayan  -> N = m*(g + a)
        // Durum 2: Asagi hizlanan / Yukari yavaslayan -> N = m*(g - a)
        sonuc= (durum == 1) ? (*m) * ((*(g + i)) + (*a)) : (*m) * ((*(g + i)) - (*a));
        printf("%s gezegeninde asansordeki etkin agirlik (N)= %.2f Newton\n", *(gezegenler + i), sonuc);
    }
}


// ANA PROGRAM

int main() {
    char Bilim_insani[30];
    int secim;

    printf("\n=== UZAY SIMULASYONU PROGRAMI===\n\n");
    printf("Bilim insaninin adini giriniz: ");
    scanf("%s", Bilim_insani);
    printf("Hos geldiniz Sayin %s\n", Bilim_insani);

    do {
        printf("\n**** DENEY MENUSU ***\n");
        printf(" 1 - Serbest Dusme Deneyi     \n");
        printf(" 2 - Yukari Atis Deneyi       \n");
        printf(" 3 - Agirlik Deneyi           \n");
        printf(" 4 - Kutlecekimsel Potansiyel Enerji Deneyi \n");
        printf(" 5 - Hidrostatik Basinc Deneyi\n");
        printf(" 6 - Arsimet Kaldirma Kuvveti Deneyi \n");
        printf(" 7 - Basit Sarkac Periyodu Deneyi   \n");
        printf(" 8 - Sabit Ip Gerilmesi Deneyi      \n");
        printf(" 9 - Asansor Deneyi           \n");
        printf("-1 - Programi Sonlandirma    \n");
        printf("\n");
        printf("Lutfen hangi deneyi yapmak istediginizi menuden seciniz: ");
        scanf("%d", &secim);

        if (secim == -1) break;

        double m, t, v0, h, rho, v, l, a;
        int asansorDurum;

        switch (secim) {

            case 1:
                printf("Sureyi (t) saniye cinsinden giriniz: ");
                scanf("%lf", &t);
                t = (t < 0) ? -t : t; // Ternary operator ile deger negatif girildiyse pozitif yapiyoruz
                serbest_dusme(yercekimi_ivmeleri, &t);
                break;

            case 2:
                printf("Cismin kac m/s hizla (v0) firlatildigini giriniz: ");
                scanf("%lf", &v0);
                v0 = (v0 < 0) ? -v0 : v0;   // Ternary operator ile deger negatif girildiyse pozitif yapiyoruz
                yukari_atis(yercekimi_ivmeleri, &v0);
                break;

            case 3:
                printf("Cismin kutlesini (m) kg cinsinden giriniz: ");
                scanf("%lf", &m);
                m = (m < 0) ? -m : m;    // Ternary operator ile deger negatif girildiyse pozitif yapiyoruz
                agirlik_dny(yercekimi_ivmeleri, &m);
                break;

            case 4:
                printf("Cismin kutlesini (kg) cinsinden giriniz: ");
                scanf("%lf", &m);
                printf("Yuksekligi (h) metre cinsinden giriniz: ");
                scanf("%lf", &h);
                m = (m < 0) ? -m : m; h = (h < 0) ? -h : h;   // Ternary operator ile deger negatif girildiyse pozitif yapiyoruz
                pot_enerji(yercekimi_ivmeleri, &m, &h);
                break;

            case 5:
                printf("Sivinin birim hacmindeki kutlesini (rho) kg/m^3 cinsinden giriniz: ");
                scanf("%lf", &rho);
                printf("Sivinin derinligini(m) metre cinsinden giriniz: ");
                scanf("%lf", &h);
                rho = (rho < 0) ? -rho : rho; h = (h < 0) ? -h : h; // Ternary operator ile deger negatif girildiyse pozitif yapiyoruz
                hidro_basinc(yercekimi_ivmeleri, &rho, &h);
                break;

            case 6:
                printf("Sivinin birim hacmindeki kutlesini (rho) kg/m^3 cinsinden giriniz: ");
                scanf("%lf", &rho);
                printf("Cismin batan hacmini(V) m^3 cinsinden giriniz: ");
                scanf("%lf", &v);
                rho = (rho < 0) ? -rho : rho; v = (v < 0) ? -v : v;  // Ternary operator ile deger negatif girildiyse pozitif yapiyoruz
                arsimentKuv(yercekimi_ivmeleri, &rho, &v);
                break;

            case 7:
                printf("Sarkac uzunlugunu(L) metre cinsinden giriniz: ");
                scanf("%lf", &l);
                l = (l < 0) ? -l : l;   // Ternary operator ile deger negatif girildiyse pozitif yapiyoruz
                basit_sarkac(yercekimi_ivmeleri, &l);
                break;

            case 8:
                printf("Cismin kutlesini(m) kg cinsinden giriniz: ");
                scanf("%lf", &m);
                m = (m < 0) ? -m : m;   // Ternary operator ile deger negatif girildiyse pozitif yapiyoruz
                sbt_ip(yercekimi_ivmeleri, &m);
                break;

            case 9:
                printf("Cismin kutlesini(m) kg cinsinden giriniz: ");
                scanf("%lf", &m);
                printf("Asansor ivmesini (a) m/s^2 cinsinden giriniz: ");
                scanf("%lf", &a);
                printf("Asansor durumunu seciniz:\n");
                printf(" 1 - Yukari yonde hizlanan / Asagi yonde yavaslayan\n");
                printf(" 2 - Asagi yonde hizlanan / Yukari yonde yavaslayan\n");
                scanf("%d", &asansorDurum);
                m = (m < 0) ? -m : m; a = (a < 0) ? -a : a;
                asansor_dny(yercekimi_ivmeleri, &m, &a,asansorDurum);
                break;

            default:
                printf("Gecersiz secim, lutfen tekrar deneyin.\n");
        }
    } while (secim != -1);

    printf("\nSimulasyon bitti Sayin %s!\n", Bilim_insani);
    return 0;

}
