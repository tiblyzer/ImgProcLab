# Git segédlet

## Repository létrehozása GitHub-on

1. Kattintsunk a new gombra:

![alt text](https://github.com/tiblyzer/ImgProcLab/blob/master/segedletek/git/new_button.PNG "Logo Title Text 1")

2. Töltsük ki a mezőket az alábbi módon:

![alt text](https://github.com/tiblyzer/ImgProcLab/blob/master/segedletek/git/repo_properties.PNG "Logo Title Text 2")

* adjuk meg az új repository nevét
* hagyjuk meg public-ként az új repository-t elérhetőként
* opcionálisan kiválasztható readme file, amit markdown formátumban szerkeszthetünk, ez fog megjelenni leírásként a repository megnyitásakor
* A .gitignore állomány egy kizáró listát jelent. Teljes elérési útvonallal lehet megadni fájlokat benne felsorolva, egy sorban csak egy fájl található meg. Amelyik fájl szerepel ebben az állományban, azokat a git nem fogja figyelembe venni, és verziókövetni.
* A licenc résznél mondhatjuk meg a többi fejlesztő számára, hogy mit engedünk meg a kódbázisunkkal kapcsolatban.

## Alap Git parancsok (Git Bash)

### Repository klónozása, lokális verzió létrehozása:
```
git clone -b branchname url
```
A -b kapcsoló után adjuk meg a választott branch nevét és az url helyére bemásoljuk a távoli szerveren elérhető repository-nk url címét.

### Lokális repository kezelése

Módosítások hozzáadása a stage-be kerülés előtt:
```
git diff
```

Módosítások hozzáadása/eltávolítása:
```
git add .
git add path
git rm --cached path
```

A path helyére írjuk be a hozzáadandó módosított fájl elérési útvonalát. Megadható mappanév is, ilyenkor az egész mappábban megtalálható összes módosítást felveszi a rendszer a stage-be (módosítások ideiglenes tárolója a véglegesítés előtt).
Az add parancs esetében, ha pontot írunk, akkor az összes módosítást egyszerre felveszi a stage-be.

Módosítások véglegesítése:
```
git commit -m "message"
```

A commit esetében a message helyére leírjuk egy rövid bövített mondatban, hogy mit módosítottunk.

Felhasználói adatok beállítása:
```
git config --global user.name "github_username"
git config --global user.email "github_alias_email"

```

Branch létrehozása:
```
git checkout -b newbranch
```

Branch váltása:
```
git checkout branchname
```

Branch egyesítése a másikkal:
```
git checkout branchname
git merge mergableBranch
```

Legelőször arra a branchra váltunk át, amihez hozzácsatoljuk a másikat, ezután a merge parancs után beírjuk azt a branch nevét amit egyesíteni fogunk.

Lokális módosítások feltöltése a távoli szerverre:
```
git push -u origin branchname
```