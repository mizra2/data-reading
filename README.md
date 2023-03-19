# Data Reading Project

A simple dictionary based on a linked list to store information from a dataset about the City of Melbourne part of University Of Melbourne, COMP20003 Project 1 (2022 Semester 2). 



## Execution Dict1

To run dict1 run

```bash
  make -B dict1
```

Sample Execution Dict1

```bash
./dict1 1 dataset_1000.csv output.txt < queryfile
```

Sample output

```text
Drummond Street between Pelham Street and Grattan Street
--> footpath_id: 28948 || address: Drummond Street between Pelham Street and Grattan Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 1.02 || distance: 64.57 || grade1in: 63.3 || mcc_id: 1384459 || mccid_int: 20546 || rlmax: 42.32 || rlmin: 41.30 || segside: East || statusid: 2 || streetid: 583 || street_group: 29566 || start_lat: -37.802858 || start_lon: 144.968182 || end_lat: -37.802148 || end_lon: 144.968370 || 
--> footpath_id: 29753 || address: Drummond Street between Pelham Street and Grattan Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 0.61 || distance: 40.26 || grade1in: 66.0 || mcc_id: 1388956 || mccid_int: 20546 || rlmax: 43.31 || rlmin: 42.70 || segside: East || statusid: 2 || streetid: 583 || street_group: 29753 || start_lat: -37.802108 || start_lon: 144.968340 || end_lat: -37.801593 || end_lon: 144.968462 || 
--> footpath_id: 29359 || address: Drummond Street between Pelham Street and Grattan Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 3.45 || distance: 202.79 || grade1in: 58.8 || mcc_id: 1384369 || mccid_int: 20546 || rlmax: 44.31 || rlmin: 40.86 || segside: West || statusid: 2 || streetid: 583 || street_group: 30061 || start_lat: -37.802826 || start_lon: 144.967906 || end_lat: -37.801028 || end_lon: 144.968293 || 
Swanston Street

```

With the following output to stdout:
```text
Drummond Street between Pelham Street and Grattan Street --> 3
Swanston Street --> NOTFOUND
```

## Execution Dict2

To run dict 2 run

```bash
  make -B dict2
```

Sample Execution Dict2

```bash
./dict2 2 dataset_1000.csv output.txt < queryfile
```

Sample output

```text
20.49
--> footpath_id: 30506 || address: Rathdowne Street between Carlton Street and Faraday Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 3.02 || distance: 61.86 || grade1in: 20.5 || mcc_id: 1389885 || mccid_int: 20561 || rlmax: 40.7 || rlmin: 37.68 || segside: East || statusid: 2 || streetid: 1024 || street_group: 30882 || start_lat: -37.79934541 || start_lon: 144.9703623 || end_lat: -37.80018581 || end_lon: 144.9701767 ||
6
--> footpath_id: 28120 || address: Argyle Place East from Lygon Street || clue_sa: Carlton || asset_type: Road Footway || deltaz: 0.17 || distance: 1.04 || grade1in: 6.1 || mcc_id: 1389857 || mccid_int: 20727 || rlmax: 39.52 || rlmin: 39.35 || segside: || statusid: 3 || streetid: 396 || street_group: 28700 || start_lat: -37.80359949 || start_lon: 144.9671894 || end_lat: -37.80354208 || end_lon: 144.966623 ||

```

With the following output to stdout:
```text
20.49 --> 20.5
6 --> 6.1
```
## Authors

- [@mizra](https://www.github.com/mizra2)
