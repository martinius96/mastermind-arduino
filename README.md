# Mastermind - Arduino
| Hráč 1 (háda) <img src="https://image.flaticon.com/icons/svg/236/236831.svg" width="64" height="64"> | Používateľ <img src="https://www.makerspaces.com/wp-content/uploads/2017/08/381932-arduino-atmega-circuit-component-current-electric-.png" width="64" height="64"> |
| ------------- | ------------- |
| Úlohou hráča je uhádnuť čísla druhého hráča a aj ich poradie | V úlohe mikrokontróler Arduino Uno, alebo iný, prípadne AtMega čip.|
| Hráč na vstup do systému využíva 5x pushbutton, pričom 4 z tlačidiel fungujú ako inkrementátor čísla na tej danej pozícii v rozsahu 0-9.  | Vygeneruje číslo 0000-9999, ktoré bude hráč hádať, **pričom sa čísla neopakujú!**|
| Piatym tlačidlom sa údaje odošlú na kontrolu. Priráta sa pokus, vyhodnotí sa kombinácia.  | V prípade uhádnutia farby i pozície rozsvieti príslušnú diódu na zeleno.|
| Dáta sa zapisujú a sú vizualizované aj na LCD displej.  | V prípade neuhádnutia farby, alebo pozície rozsvieti príslušnú diódu na červeno.|
| V prípade, že hráč uhádne číslo a aj jeho pozíciu, rozsvieti sa zelená dióda na tej danej pozícii.  |  Arduino overuje aj počet krokov (ťahov), ktoré hráč použil, skúma, či je hra ukončená. |
| V opačnom prípade pri neuhádnutí čísla, respektíve pri uhádnutí čísla ale neuhádnutí pozície sa zosvieti červená dióda na znak nepravdy.  | Hra sa končí, ak hráč 1 uhádne všetky čísla aj ich pozície (všetky 4 diódy budú zelené), vstup sa zablokuje, alebo pri neúspešnej hre s dosiahnutím 10 pokusov.|
| Pre hráča sa hra končí pri presiahnutí 10 pokusov, alebo pri uhádnutí kombinácie.| O stave hry je používateľ vždy informovaný na displeji.|
