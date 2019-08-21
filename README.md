# Popis - Mastermind logika
| Hráč 1 (háda) <img src="https://image.flaticon.com/icons/svg/236/236831.svg" width="64" height="64"> | Hráč 2 (Arduino-generátor) <img src="https://www.makerspaces.com/wp-content/uploads/2017/08/381932-arduino-atmega-circuit-component-current-electric-.png" width="64" height="64"> |
| ------------- | ------------- |
| Úlohou hráča je uhádnuť čísla druhého hráča a aj ich poradie | V úlohe mikrokontróler Arduino Uno, alebo iný, prípadne AtMega čip|
| Hráč na vstup do systému využíva 5x pushbutton, pričom 4 z tlačidiel fungujú ako inkrementátor čísla na tej danej pozícii v rozsahu 0-9  | Vygeneruje číslo 0000-9999, ktoré bude hráč hádať, **pričom sa čísla neopakujú!**|
| Piatym tlačidlom sa údaje odošlú na kontrolu. Priráta sa pokus, vyhodnotí sa kombinácia  | V prípade uhádnutia farby i pozície rozsvieti príslušnú diódu na zeleno|
| Dáta sa zapisujú a sú vizualizované aj na LCD displej  | V prípade neuhádnutia farby, alebo pozície rozsvieti príslušnú diódu na červeno|
| V prípade, že hráč uhádne číslo a aj jeho pozíciu, rozsvieti sa zelená dióda na tej danej pozícii  |  Arduino overuje aj počet krokov (ťahov), ktoré hráč použil, skúma, či je hra ukončená |
| V opačnom prípade pri neuhádnutí čísla, respektíve pri uhádnutí čísla ale neuhádnutí pozície sa zosvieti červená dióda na znak nepravdy | Hra sa končí, ak hráč 1 uhádne všetky čísla aj ich pozície (všetky 4 diódy budú zelené), vstup sa zablokuje, alebo pri neúspešnej hre s dosiahnutím 10 pokusov|
| Pre hráča sa hra končí pri presiahnutí 10 pokusov, alebo pri uhádnutí kombinácie| O stave hry je používateľ vždy informovaný na displeji|

# Hardvér pre projekt
Arduino Uno R3 <img src="https://s3-ap-northeast-1.amazonaws.com/switch-science-intl/contents/small/789_201602_102_tBuTiHx.jpg" width="64" height="64">

4x RGB LED WS2812 (jeden modul) <img src="https://rukminim1.flixcart.com/image/128/128/jen4vww0/learning-toy/y/c/n/ws2812-8-bit-stright-rgb-led-driver-for-flight-controller-original-imaf3ah6eymgyhpx.jpeg?q=70" width="64" height="64">

5x tlačidlo - spínacie <img src="https://http2.mlstatic.com/push-button-cuadrado-6x6x73mm-con-boton-redondo-D_NQ_NP_824716-MPE28317610646_102018-F.jpg" width="64" height="64">

LCD 20x4 alebo 16x2 <img src="https://e.allegroimg.com/s128/03e03d/70fb2d2a4ea2949c1b2f8c0154de" width="64" height="64">

I2C prevodník pre LCD <img src="https://5.allegroimg.com/s128/0323c6/28d4e43340b9ac50b03ae628e8a5" width="64" height="64">

# Zapojenie
|LCD displej s I2C prevodníkom|	Arduino Uno|
| ------------- | ------------- |
|Vcc	|5V|
|GND	|GND|
|SDA	|A4 (SDA)|
|SCK/SCL|	A5 (SCK/SCL)|
|**Pushbutton**|	**Arduino Uno**|
|IN 1	|D6|
|IN 2	|D5|
|IN 3	|D4|
|IN 4	|D3|
|Enter|	D2|
|**RGB led diódy**|	**Arduino Uno**|
|DIN	|D13|
|GND	|GND|
|5V	|-|
#
**5V pin sa pripája na externý zdroj z dôvodu veľkého nárazového odberu prúdu zvlášť pri rozsvietení všetkých diód, rádovo 200mA.**

# Zapojenie komponentov:
<img src="https://i.imgur.com/5y42VPk.jpg" style="display: block; max-width: 100%; height: auto;">

# DEBUG OFF:
<img src="https://i.imgur.com/TCVXVBB.png" style="display: block; max-width: 100%; height: auto;">

# DEBUG ON (vidieť hľadané číslo):
<img src="https://i.imgur.com/SkdVJsP.jpg" style="display: block; max-width: 100%; height: auto;">

# Výhra hráča:
<img src="https://i.imgur.com/8CBzzhB.jpg" style="display: block; max-width: 100%; height: auto;">

# Prehra hráča:
<img src="https://i.imgur.com/f8qZGTv.jpg" style="display: block; max-width: 100%; height: auto;">
