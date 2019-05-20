# Mastermind - Arduino
| Hráč 1 (háda) <img src="https://image.flaticon.com/icons/svg/236/236831.svg" width="64" height="64"> | Používateľ <img src="https://www.makerspaces.com/wp-content/uploads/2017/08/381932-arduino-atmega-circuit-component-current-electric-.png" width="64" height="64"> |
| ------------- | ------------- |
| Úlohou hráča je uhádnuť čísla druhého hráča a aj ich poradie | Fyzicky prikladá NFC tag/kľúčenku/náramok/kartu|
| Hráč na vstup do systému využíva 5x pushbutton, pričom 4 z tlačidiel fungujú ako inkrementátor čísla na tej danej pozícii v rozsahu 0-9.  | Pri overeni sú mu odistené dvere na 5 sekúnd|
| Piatym tlačidlom sa údaje odošlú na kontrolu. Priráta sa pokus, vyhodnotí sa kombinácia.  | Pri neoverení používateľa sa jazýček nevtiahne  |
| Dáta sa zapisujú a sú vizualizované aj na LCD displej.  | Používateľ o overení/neoverení nie je informovaný (led/buzzer)|
| V prípade, že hráč uhádne číslo a aj jeho pozíciu, rozsvieti sa zelená dióda na tej danej pozícii.  |  Informovanie používateľa o výsleku overenia cez diódu/buzzer (len platená verzia) |
| V opačnom prípade pri neuhádnutí čísla, respektíve pri uhádnutí čísla ale neuhádnutí pozície sa zosvieti červená dióda na znak nepravdy.  | Pre hráča sa hra končí pri presiahnutí 10 pokusov, alebo pri uhádnutí kombinácie.|
