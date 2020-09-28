# Gyakorló feladatok

1. Írjon osztályt, amely átmásolja az adott képről a teljes kék csatornát!
2. Írjon osztályt, amely lehetővé teszi az adott kép intenzitásának változatását (expozíció-kompenzáció)!
3. Írjon osztályt, amely átkonvertálja az adott képet szürkeskálásra!
4. Írjon osztályt, amely százalékosan képes módosítani bármelyik színcsatornát!
5. Írjon osztályt, amely százalékosan képes módosítani a lila komponenst az adott képen!
6. Írjon osztályt, amely képes a megadott képen fehéregyensúly változtatásra!

## Segítség a feladatokhoz

1. Csak az adott (kék csatorna) eredeti értéke marad meg, a többi kinullázódik (lásd demoCopyColorChannels metódus).
2. RGB esetében mindhárom csatorna ugyanazzal az értékkel (+20) változik az adott pixelnél. HSV esetében csak az intenzitás (Value) csatorna értéke módosul.
4. Itt csak az RGB színmodell szükséges. A százalékos módosítás itt azt jelenti, hogy a kép minden egyes pixelén az adott színcsatorna értéke csökken a felhasználó által megadott százalékos értékkel. 
   
> Példa: 
> - Red = 50
> - Green = 20
> - Blue = 30
> - Percentage(Red) = -10%
> - Percentage(Green) = +20%
> - Percentage(Blue) = +5%
>   
> Új értékek:
> - Red = 50 * (1-0.1) = 45
> - Green = 24
> - Blue = 31

5. A feladatot HSV színtérben érdemes megoldani. A módosítás a szaturáció és a világosság csatornákra vonatkozik.  
A Hue csatornán először meghatározzuk a lila szín értéktartományát, ezt követően százalékosan módosul külön-külön a másik két csatorna. 

6. A feladatot RGB színtérben lehet megoldani. A lényeg, hogy a kép pixelei vagy a kék, vagy a sárga irányába tolódnak el.
A kék csatorna adott, a sárga szín a piros és a zöld csatornából keverhető ki. A megadott eltolás mértéke alapján módosulnak vagy a kék csatornán a pixelek értékei, vagy a másik piros és zöld csatornán egyszerre ugyanazon értékkel.