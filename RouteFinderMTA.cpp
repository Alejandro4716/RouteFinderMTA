
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std; 

class Train {
public:
    string name;
    vector<string> stops;
    //constructor to initialize train name and stops
    Train (string trainName, vector<string> trainStops){
        name = trainName; 
        stops = trainStops; 
    }
    
    //method to print all stops for a train
    void PrintStops (){
        for (int i=0; i<stops.size(); i++){
            cout<< stops.at(i) <<endl; 
        }
    }
};

//function protoypes
void MakeTrainList (string stop, vector<Train>& trainVector, vector<Train>& trainList);
void DirectRoute(vector<Train>& endingStationTrains, vector<Train>& startingStationTrains);
void FindPossibleTransferStops (vector<Train>& StartingStationTrains, vector<Train>& endingStationTrains, string &transferStop);

int main() {

    // 1 train stops 
    vector<string> oneTrainStops = {
        "VAN CORTLANDT PARK 242",
        "238 STREET",
        "231 STREET",
        "MARBLE HILL 225 STREET",
        "215 STREET",
        "207 STREET",
        "DYCKMAN STREET",
        "191 STREET",
        "181 STREET",
        "168 STREET", 
        "157 STREET",
        "145 STREET",
        "137 STREET CITY COLLEGE",
        "125 STREET",
        "116 STREET COLUMBIA UNIVERSITY",
        "CATHEDRAL PARKWAY 110 STREET",
        "103 STREET",
        "96 STREET",
        "86 STREET",
        "79 STREET",
        "72 STREET",
        "66 STREET LINCOLN CENTER",
        "59 STREET COLUMBUS CIRCLE",
        "WEST 50 STREET AND BROADWAY",
        "TIMES SQUARE 42 STREET",
        "34 STREET PENN STATION",
        "28 STREET",
        "23 STREET",
        "18 STREET",
        "14 STREET",
        "CHRISTOPHER STREET SHERIDAN SQUARE",
        "HOUSTON STREET",
        "CANAL STREET",
        "FRANKLIN STREET",
        "CHAMBERS STREET",
        "WORLD TRADE CENTER CORTLANDT",
        "RECTOR STREET",
        "SOUTH FERRY"
    }; 
    
    
    // 2 train stops 
    vector <string> twoTrainStops = {
        "WAKEFIELD 241 STREET",
        "NEREID AVENUE",
        "233 STREET",
        "225 STREET",
        "219 STREET",
        "GUN HILL ROAD",
        "BURKE AVENUE",
        "ALLERTON AVENUE",
        "PELHAME PARKWAY",
        "BRONX PARK EAST",
        "EAST 180 STREET",
        "WEST FARMS SQUARE EAST TREMONT AVENUE",
        "174 STREET",
        "FREEMAN STREET",
        "SIMPSON STREET",
        "INTERVALE AVENUE",
        "PROSPECT AVENUE",
        "JACKSON AVENUE",
        "3 AVENUE 149 STRETT",
        "149 ST GRAND CONCOURSE",
        "135 STREET",
        "125 STREET",
        "116 STREET",
        "CENTRAL PARK NORTH 110 STREET",
        "96 STREET",
        "72 STREET",
        "TIMES SQUARE 42 STREET",
        "34 STREET PENN STATION",
        "14 STREET",
        "CHAMBERS STREET",
        "PARK PLACE",
        "FULTON STREET",
        "WALL STREET",
        "CLARK STREET",
        "BOROUGH HALL",
        "HOYT STREET",
        "NEVINS STREET",
        "ATLANTIC AVENUE BARCLAYS CENTER",
        "BERGAN STREET",
        "GRAND ARMY PLAZA",
        "EASTERN PARKWAY BROOKLYN MUSEUM",
        "FRANKLIN AVENUE MEDGAR EVERS COLLEGE",
        "PRESIDENT STREET MEDGARS EVERS COLLEGE",
        "STERLING STREET",
        "WINTHROP STREET",
        "CHURCH AVENUE",
        "BEVERLY ROAD",
        "NEWKIRK AVENUE LITTLE HAITI",
        "FLATBUSH AVENUE BROOKLYN COLLEGE"
    };
    
    
    // 3 TRAIN STOPS 
    vector <string> threeTrainStops = {
        "HARLEM 148 STREET",
        "145 STREET",
        "135 STREET",
        "125 STREET",
        "116 STREET",
        "CENTRAL PARK NORTH 110 STREET",
        "96 STREET",
        "72 STREET",
        "TIMES SQUARE 42 STREET",
        "34 STREET PENN STATION",
        "14 STREET",
        "CHAMBERS STREET",
        "PARK PLACE",
        "FULTON STREET",
        "WALL STREET",
        "CLARK STREET",
        "BOROUGH HALL",
        "HOYT STREET",
        "NEVINS STREET",
        "ATLANTIC AVENUE BARCLAYS CENTER",
        "BERGEN STREET",
        "GRAND ARMY PLAZA",
        "EASTERN PARKWAY BROOKLYN MUSEUM",
        "FRANKLIN AVENUE MEDGAR EVERS COLLEGE",
        "NOSTRAND AVENUE",
        "KINGSTON AVENUE",
        "CROWN HEIGHTS UTICA AVENUE",
        "SUTTER AVENUE RUTLAND ROAD",
        "SARATOGA AVENUE",
        "ROCKAWAY AVENUE",
        "JUNIUS STREET",
        "PENNSYLVANIA AVENUE",
        "VAN SICLEN AVENUE",
        "NEW LOTS AVENUE"
    };
    
    
    // 4 train stops 
    vector <string> fourTrainStops = {
        "WOODLAWN",
        "MOSHOLU PARKWAY",
        "BEDFORD PARK BOULEVARD LEHMAN COLLEGE",
        "KINGSBRIDGE ROAD",
        "FORDHAM ROAD",
        "183 STREET",
        "BURNSIDE AVENUE",
        "176 STREET",
        "MOUNT EDEN AVENUE",
        "170 STREET",
        "167 STREET",
        "161 STREET YANKEE STADIUM",
        "149 STREET GRAND CONCOURSE",
        "138 STREET GRAND CONCOURSE",
        "125 STREET",
        "86 STREET",
        "59 STREET",
        "GRAND CENTRAL 42 STREET",
        "14 STREET UNION SQUARE",
        "BROOKLYN BRIDGE CITY HALL",
        "FULTON STREET",
        "WALL STREET",
        "BOWLING GREEN",
        "BOROUGH HALL",
        "NEVINS STREET",
        "ATLANTIC AVENUE BARCLAYS CENTER",
        "FRANKLIN AVENUE MEDGAR EVERS COLLEGE",
        "CROWN HEIGHTS UTICA AVENUE"
    };
    
    
    // 5 train stops 
    vector <string> fiveTrainStops = {
        //EASTCHESTER DYRE BRANCH
        "EASTCHESTER DYRE AVENUE",
        "BAYCHESTER AVENUE",
        "GUN HILL ROAD",
        "PELHAM PARKWAY",
        "MORRIS PARK",
        "EAST 180 STREET",
        "WEST FARMS SQUARE EAST TREMONT AVENUE",
        "174 STREET",
        "FREEMAN STREET",
        "SIMPSON STREET",
        "INTERVALE AVENUE",
        "PROSPECT AVENUE",
        "JACKSON AVENUE",
        "3 AVENUE 149 STREET",
        "149 STREET GRAND CONCOURSE",
        "138 STREET GRAND CONCOURSE",
        "125 STREET",
        "86 STREET",
        "59 STREET",
        "GRAND CENTRAL 42 STREET",
        "14 STREET UNION SQUARE",
        "BROOKLYN BRIDGE CITY HALL",
        "FULTON STREET",
        "WALL STREET",
        "BOWLING GREEN",
        
        //NEREID AVENUE BRANCH
        "NEREID AVENUE",
        "233 STREET",
        "225 STREET",
        "219 STREET",
        "GUN HILL ROAD",
        "BURKE AVENUE",
        "ALBERTON AVENUE",
        "PELHAM PARKWAY",
        "BRONX PARK EAST",
        
        //BROOKLYN
        "BOROUGH HALL",
        "NEVINS STREET",
        "ATLANTIC AVENUE BARCLAYS CENTER",
        "FRANKLIN AVENUE MEDGAR EVERS COLLEGE",
        "PRESIDENT STREET MEDGAR EVERS COLLEGE",
        "STERLING STREET",
        "WINTHROP STREET",
        "CHURCH AVENUE",
        "BEVERLY ROAD",
        "NEWKIRK AVENUE LITTLE HAITI",
        "FLATBUSH AVENUE BROOKLYN COLLEGE"
    };
    
    
    // 6 train stops 
    vector<string> sixTrainStops = {
        "PELHAM BAY PARK",
        "BUHRE AVENUE",
        "MIDDLETOWN ROAD",
        "WESTCHESTER SQUARE EAST TREMONT AVENUE",
        "ZEREGA AVENUE",
        "CASTLE HILL AVENUE",
        "PARKCHESTER",
        "ST. LAWRENCE AVENUE",
        "MORRISON AVENUE SOUNDVIEW",
        "ELDER AVENUE",
        "WHITLOCK AVENUE",
        "HUNTS POINT AVENUE",
        "LONGWOOD AVENUE",
        "EAST 149 STREET",
        "EAST 143 STREET MARY'S STREET",
        "CYPRESS AVENUE",
        "BROOK AVENUE",
        "3 AVENUE 138 STREET",
        "125 STREET",
        "116 STREET",
        "110 STREET",
        "103 STREET",
        "96 STREET",
        "86 STREET",
        "77 STREET",
        "68 STREET HUNTER COLLEGE",
        "59 STREET",
        "51 STREET",
        "GRAND CENTRAL 42 STREET",
        "33 STREET",
        "28 STREET",
        "23 STREET",
        "14 STREET UNION SQUARE",
        "ASTOR PLACE",
        "BLEEKER STREET",
        "SPRING STREET",
        "CANAL STREET",
        "BROOKLYN BRIDGE CITY HALL"
    };
    
    
    // 7 TRAIN STOPS
    vector<string> sevenTrainStops = {
        "FLUSHING MAIN STREET",
        "METS WILLETS POINT",
        "111 STREET",
        "103 STREET CORONA PLAZA",
        "JUNCTION BOULEVARD",
        "90 STREET ELMHURST AVENUE",
        "82 ST JACKSON HEIGHTS",
        "74 STREET BROADWAY",
        "69 STREET",
        "61 STREET WOODSIDE",
        "52 STREET",
        "46 STREET BLISS STREET",
        "40 STREET LOWERY STREET",
        "33 STREET RAWSON STREET",
        "QUEENSBORO PLAZA",
        "COURT SQUARE",
        "HUNTERS POINT AVENUE",
        "VERNON BOULEVARD JACKSON AVENUE",
        "GRAND CENTRAL 42 STREET",
        "5 AVENUE",
        "TIMES SQUARE 42 STREET",
        "34 STREET HUDSON YARDS"
    };
    
    
    // a train stops 
    vector<string> aTrainStops = {
        "INWOOD 207 STREET",
        "DYCKMAN STREET",
        "190 STREET",
        "181 STREET",
        "175 STREET",
        "168 STREET",
        "145 STREET",
        "125 STREET",
        "59 STREET COLUMBUS CIRCLE",
        "42 ST PORT AUTHORITY BUS TERMINAL",
        "34 STREET PENN STATION",
        "14 STREET",
        "WEST 4 WASHINGTON SQUARE",
        "CANAL STREET",
        "CHAMBERS STREET",
        "FULTON STREET",
        "HIGH STREET",
        "JAY STREET METROTECH",
        "HOYT SCHERMERHORN",
        "NOSTRAND AVENUE",
        "UTICA AVENUE",
        "BROADWAY JUNCTION",
        "EUCLID AVENUE",
        "GRANT AVENUE",
        "80 STREET",
        "88 STREET",
        "ROCKAWAY BOULEVARD",
        
        //LEFFERTS BRANCH
        "104 STREET",
        "111 STREET",
        "OZONE PARK LEFFERTS BOULEVARD",
        
        
        // FAR ROCKAWAY BRANCH
        "AQUEDUCT RACETRACK",
        "AQUEDUCT NORTH CONDUIT AVENUE",
        "HOWARD BEACH JFK AIRPORT",
        "BROAD CHANNEL",
        "BEACH 67 STREET",
        "BEACH 60 STREET",
        "BEACH 44 STREET",
        "BEACH 36 STREET",
        "BEACH 25 STREET",
        "FAR ROCKAWAY MOTT AVENUE",
        
        // ROCKAWAY PARK BRANCH
        "BEACH 90 STREET",
        "BEACH 98 STREET",
        "BEACH 105 STREET",
        "ROCKAWAY PARK BEACH 116 STREET"
    };
     
        
    // a TRAIN STOPS 
    vector<string> bTrainStops = {
        "BEDFORD PARK BOULEVARD",
        "KINGSBRIDGE ROAD",
        "FORDHAM ROAD",
        "182 183 STREETS",
        "TREMONT AVENUE",
        "174 175 STREETS",
        "170 STREET",
        "167 STREET",
        "161 STREET YANKEE STADIUM",
        "155 STREET",
        "145 STREET",
        "135 STREET",
        "125 STREET",
        "116 STREET",
        "CATHEDRAL PARKWAY 110 STREET",
        "103 STREET",
        "96 STREET",
        "86 STREET",
        "81 STREET MUSEUM OF NATURAL HISTORY",
        "72 STREET",
        "59 STREET COLUMBUS CIRCLE",
        "7 AVENUE",
        "47 50 STREETS ROCKEFELLER CENTER",
        "42 STREET BRYANT PARK",
        "34 STREET HERALD SQUARE",
        "WEST 4 WASHINGTON SQUARE PARK",
        "BROADWAY LAFAYETTE STREET",
        "GRAND STREET",
        "DEKALB AVENUE",
        "ATLANTIC AVENUE BARCLAYS CENTER",
        "7 AVENUE (BROOKLYN)", 
        "PROSPECT PARK",
        "CHURCH AVENUE",
        "NEWKIRK PLAZA",
        "KINGS HIGHWAY",
        "SHEEPSHEAD BAY",
        "BRIGHTON BEACH"
    };
    
    
    // c train stops 
    vector<string> cTrainStops = {
        "168 STREET",
        "163 STREET AMSTERDAM AVENUE",
        "155 STREET",
        "145 STREET",
        "135 STREET",
        "125 STREET",
        "116 STREET",
        "CATHEDRAL PARKWAY 110 STREET",
        "103 STREET",
        "96 STREET",
        "86 STREET",
        "81 STREET MUSEUM OF NATURAL HISTORY",
        "72 STREET",
        "59 STREET COLUMBUS CIRCLE",
        "50 STREET",
        "42 STREET PORT AUTHORITY BUS TERMINAL",
        "34 STREET PENN STATION",
        "23 STREET",
        "14 STREET",
        "WEST 4 WASHINGTON SQUARE",
        "SPRING STREET",
        "CANAL STREET",
        "CHAMBERS STREET",
        "FULTON STREET",
        "HIGH STREET",
        "JAY STREET METROTECH",
        "HOYT SCHERMERHORN",
        "LAFAYETTE AVENUE",
        "CLINTON WASHINGTON AVENUES",
        "FRANKLIN AVENUE",
        "NOSTRAND AVENUE",
        "KINGSTON THROOP AVENUES",
        "UTICA AVENUE",
        "RALPH AVENUE",
        "ROCKAWAY AVENUE",
        "BROADWAY JUNCTION",
        "LIBERTY AVENUE",
        "VAN SICLEN AVENUE",
        "SHEPHERD AVENUE",
        "EUCLID AVENUE"
    };
    
    
    //d train stops
    vector<string> dTrainStops = {
        "NORWOOD 205 STREET",
        "BEDFORD PARK BOULEVARD",
        "KINGSBRIDGE ROAD",
        "FORDHAM ROAD",
        "182 183 STREETS",
        "TREMONT AVENUE",
        "174 175 STREETS",
        "170 STREET",
        "167 STREET",
        "161 STREET YANKEE STADIUM",
        "155 STREET",
        "145 STREET",
        "125 STREET",
        "59 STREET COLUMBUS CIRCLE",
        "7 AVENUE",
        "47 50 STREETS ROCKEFELLER CENTER",
        "42 STREET BRYANT PARK",
        "34 STREET HERALD SQUARE",
        "WEST 4 STREET WASHINGTON SQUARE",
        "BROADWAY LAFAYETTE STREET",
        "GRAND STREET",
        "ATLANTIC AVENUE BARCLAYS CENTER",
        "36 STREET",
        "9 AVENEUE", 
        "FORT HAMILTON PARKWAY",
        "50 STREET (BROOKLYN)",
        "55 STREET",
        "62 STREET",
        "71 STREET",
        "79 STREET",
        "18 AVENUE",
        "20 AVENUE",
        "BAY PARKWAY",
        "25 AVENUE",
        "BAY 50 STREET",
        "CONEY ISLAND STILLWELL AVENUE"
    };
    
    
    //e train stops
    vector<string> eTrainStops = {
        "JAMAICA CENTER PARSONS BOULEVARD ARCHER AVENUE",
        "SUTPHIN BOULEVARD ARCHER AVENUE JFK AIRPORT",
        "JAMAICA VAN WYCK",
        "BRIARWOOD",
        "KEW GARDENS UNION TURNPIKE",
        "75 AVENUE",
        "FOREST HILLS 71 AVENUE",
        "JACKSON HEIGHTS ROOSEVELT AVENUE",
        "QUEENS PLAZA",
        "COURT SQUARE 23 STREET",
        "LEXINGTON AVENUE 53 STREET",
        "5 AVENUE 53 STREET",
        "50 STREET",
        "42 STREET PORT AUTHORITY BUS TERMINAL",
        "34 STREET PENN STATION",
        "23 STREET",
        "14 STREET",
        "WEST 4 WASHINGTON SQUARE",
        "SPRING STREET",
        "CANAL STREET",
        "WORLD TRADE CENTER"
    };
    
    
    //f train stops
    vector<string> fTrainStops = {
        "JAMAICA 179 STREET",
        "169 STREET",
        "PARSONS BOULEVARD",
        "SUTPHIN BOULEVARD",
        "BRIARWOOD",
        "KEW GARDENS UNION TURNPIKE",
        "75 AVENUE",
        "FOREST HILLS 71 AVENUE",
        "JACKSON HEIGHTS ROOSEVELT AVENUE",
        "21 STREET QUEENSBRIDGE",
        "ROOSEVELT ISLAND",
        "LEXINGTON AVENUE 63 STREET",
        "57 STREET",
        "47 50 STREETS ROCKEFELLER CENTER",
        "42 STREET BRYANT PARK",
        "34 STREET HERLAD SQUARE",
        "23 STREET",
        "14 STREET",
        "WEST 4 WASHINGTON SQUARE",
        "BROADWAY LAFAYETTE STREET",
        "2 AVENUE",
        "DELANCEY STREET ESSEX STREET",
        "EAST BROADWAY",
        "YORK STREET",
        "JAY STREET METROTECH",
        "BERGEN STREET",
        "CARROLL STREET",
        "SMITH 9 STREET",
        "4 AVENUE",
        "7 AVENUE (BROOKLYN)",
        "15 STREET PROSPECT PARK",
        "FORT HAMILTON PARKWAY",
        "CHURCH AVENUE",
        "DITMAS AVENUE",
        "18 AVENUE",
        "AVENUE 1",
        "BAY PARKWAY",
        "AVENUE N",
        "KINGS HIGHWAY",
        "AVENUE X",
        "NEPTUNE AVENUE",
        "WEST 8 STREET NY AQUARIUM",
        "CONEY ISLAND STILLWELL AVENUE"
    };
    
    
    //g train stops
    vector<string> gTrainStops = {
      "COURT SQUARE",
      "21 STREET",
      "GREENPOINT AVENUE",
      "NASSAU AVENUE",
      "METROPOLITAN AVENUE",
      "BROADWAY",
      "FLUSHING AVENUE (G)",
      "MYRTLE WILLOUGHBY AVENUES",
      "BEDFORD-NOSTRAND AVENUES",
      "CLASSON AVENUE",
      "CLINTON WASHINGTON AVENUE",
      "FULTON STREET (G)",
      "HOYT SCHERMERHORN",
      "BERGEN STREET",
      "CARROLL STREET",
      "SMITH 9 STREETS",
      "4 AVENUE AND 9 STREETS",
      "7 AVENUE",
      "15 STREET PROSPECT PARK",
      "FORT HAMILTON PARKWAY",
      "CHURCH AVENUE"
    };
    
    
    // j train stops 
    vector<string> jTrainStops = {
        "JAMAICA CENTER PARSONS BOULEVARD ARCHER AVENUE",
        "SUTPHIN BOULEVARD ARCHER AVENUE JFK AIRPORT",
        "121 STREET",
        "111 STREET",
        "104 STREET",
        "WOODHAVEN BOULEVARD",
        "85 STREET FOREST PARKWAY",
        "75 STREET ELDERTS LANE",
        "CYPRESS HILLS",
        "CRESCENT STREET",
        "NORWOOD AVENUE",
        "CLEVELAND STREET",
        "VAN SICLEN AVENUE",
        "ALABAMA AVENUE",
        "BROADWAY JUNCTION",
        "CHAUNCEY STREET",
        "HALSEY STREET",
        "GATES AVENUE",
        "KOSCIUSZKO STREET",
        "MYRTLE AVENUE",
        "FLUSHING AVENUE",
        "LORIMER STREET",
        "HEWES STREET",
        "MARCY AVENUE",
        "DELANCEY STREET ESSEX STREET",
        "BOWERY",
        "CANAL STREET",
        "CHAMBERS STREET",
        "FULTON STREET",
        "BROAD STREET"
    };


    //l train stops
    vector<string> lTrainStops = {
      "8 AVENUE",
      "6 AVENUE", 
      "14 STREET UNION SQUARE",
      "3 AVENUE",
      "1 AVENUE",
      "BEDFORD AVENUE",
      "LORIMER STREET",
      "GRAHAM AVENUE",
      "GRAND STREET",
      "MONTROSE AVENUE",
      "MORGAN AVENUE",
      "JEFFERSON STREET",
      "DEKALB AVENUE",
      "MYRTLE WYCKOFF AVENUE",
      "HALSEY STREET",
      "WILSON AVENUE",
      "BUSHWICK AVENUE ABERDEEN STREET",
      "BROADWAY JUNCTION",
      "ATLANTIC AVENUE",
      "SUTTER AVENUE",
      "LIVONIA AVENUE",
      "NEW LOTS AVENUE",
      "EAST 105 STREET",
      "CANARSIE ROCKAWAY PARKWAY",
    };
    
    
    //m train stops  
    vector<string> mTrainStops = {
        "FOREST HILLS 71 AVENUE",
        "67 AVENUE",
        "63 DRIVE REGO PARK",
        "WOODHAVEN BOULEVARD",
        "GRAND AVENUE NEWTOWN",
        "ELMHURST AVENUE",
        "JACKSON HEIGHTS ROOSEVELT AVENUE",
        "65 STREET",
        "NORTHERN BOULEVARD",
        "46 STREET",
        "STEINWAY STREET",
        "36 STREET",
        "QUEENS PLAZA",
        "COURT SQUARE 23 STREET",
        "LEXINGTON AVENUE 53 STREET",
        "5 AVENUE 53 STREET",
        "47 50 STREET ROCKEFELLER CENTER",
        "42 STREET BRYANT PARK",
        "34 STREET HERALD SQUARE",
        "23 STREET",
        "14 STREET",
        "WEST 4 WASHINTON SQUARE",
        "BROADWAY LAFAYETTE STREET",
        "DELANCEY STREET ESSEX STREET",
        "MARCY AVENUE",
        "HEWES STREET",
        "LORIMER STREET",
        "FLUSHING AVENUE",
        "MYRTLE AVENUE",
        "CENTRAL AVENUE",
        "KNICKERBOCKER AVENUE",
        "MYRTLE WYCKOFF AVENUES",
        "SENECA AVENUE",
        "FOREST AVENUE",
        "FRESH POND ROAD",
        "MIDDLE VILLAGE METROPOLITAN AVENUE"
    };
    
    
    // n train stops
    vector<string> nTrainStops = 
    {
        "ASTORIA DITMARS BOULEVARD",
        "ASTORIA BOULEVARD",
        "30 AVENUE",
        "BROADWAY",
        "36 AVENUE",
        "39 AVENUE",
        "QUEENSBORO PLAZA",
        "LEXINGTON AVENUE 59 STREET",
        "5 AVENUE 59 STREET",
        "57 STREET 7 AVENUE",
        "49 STREET",
        "TIMES SQUARE 42 STREET",
        "34 STREET HERALD SQUARE",
        "14 STREET UNION SQUARE",
        "CANAL STREET",
        "ATLANTIC AVENUE BARCLAYS CENTER",
        "36 STREET",
        "59 STREET",
        "FORT HAMILTON PARKWAY",
        "NEW UTRECHT AVENUE",
        "18 AVENUE",
        "20 AVENUE",
        "BAY PARKWAY",
        "KINGS HIGHWAY",
        "AVENUE U",
        "86 STREET",
        "CONEY ISLAND STILLWELL AVENUE"
    }; 
    
    
    //q train stops 
    vector<string> qTrainStops = {
        "96 STREET",
        "86 STREET",
        "72 STREET",
        "LEXINGTON AVENUE 63 STREET",
        "57 STREET 7 AVENUE",
        "TIMES SQUARE 42 STREET",
        "34 STREET HERALD SQUARE",
        "14 STREET UNION SQUARE",
        "CANAL STREET",
        "DEKALB AVENUE",
        "ATLANTIC AVENUE BARCLAYS CENTER",
        "7 AVENUE",
        "PROSPECT PARK",
        "PARKSIDE AVENUE",
        "CHURCH AVENUE",
        "BEVERLY ROAD",
        "CORTELYOU ROAD",
        "NEWKIRK PLAZA",
        "AVENUE H",
        "AVENUE J",
        "AVENUE M",
        "KINGS HIGHWAY",
        "AVENUE U",
        "NECK ROAD",
        "SHEEPSHEAD BAY",
        "BRIGHTON BEACH",
        "OCEAN PARKWAY",
        "WEST 8 STREET NY AQUARIUM",
        "CONEY ISLAND STILLWELL AVENUE"
    };
    
    // r train stops
    vector<string> rTrainStops = {
        "FOREST HILLS 71 AVENUE",
        "67 AVENUE",
        "63 DRIVE REGO PARK",
        "WOODHAVEN BOULEVARD",
        "GRAND AVENUE NEWTOWN",
        "ELMHURST AVENUE",
        "JACKSON HEIGHTS ROOSEVELT AVENUE",
        "65 STREET",
        "NORTHERN BOULEVARD",
        "46 STREET",
        "STEINWAY STREET",
        "36 STREET",
        "QUEENS PLAZA",
        "LEXINGTON AVENUE 59 STREET",
        "5 AVENUE 59 STREET",
        "57 STREET 7 AVENUE",
        "49 STREET",
        "TIMES SQUARE 42 STREET",
        "34 STREET HERALD SQUARE",
        "28 STREET",
        "23 STREET",
        "14 STREET UNION SQUARE",
        "8 STREET NYU",
        "PRINCE STREET",
        "CANAL STREET",
        "CORTLANDT STREET",
        "RECTOR STREET",
        "WHITEHALL STREET SOUTH FERRY",
        "COURT STREET",
        "JAY STREET METROTECH",
        "DEKALB AVENUE",
        "ATLANTIC AVENUE BARCLAYS CENTER",
        "UNION STREET",
        "4 AVENUE 9 STREET",
        "PROSPECT AVENUE",
        "25 STREET",
        "36 STREET",
        "45 STREET",
        "53 STREET",
        "59 STREET",
        "BAY RIDGE AVENUE",
        "77 STREET",
        "86 STREET",
        "BAY RIDGE 95 STREET"
    };
    
    
    // manhattan s train stops
    vector<string> msTrainStops = {
      "TIMES SQUARE 42 STREET",
      "GRAND CENTRAL 42 STREET"
    };
    
    
    //brooklyn s train stops
    vector<string> bsTrainStops = {
        "FRANKLIN AVENUE",
        "PARK PLACE",
        "BOTANIC GARDEN",
        "PROSPECT PARK"
    };
    
    
    //queens s train stops
    vector<string> qsTrainStops ={
        "BROAD CHANNEL",
        "BEACH 90 STREET",
        "BEACH 98 STREET",
        "BEACH 105 STREET",
        "ROCKAWAY PARK BEACH 116 STREET"
    };
    
    //w train stops
    vector<string> wTrainStops = {
      "ASTORIA DITMARS BOULEVARD",
      "ASTORIA BOULEVARD",
      "30 AVENUE",
      "BROADWAY",
      "36 AVENUE",
      "39 AVENUE",
      "QUEENSBORO PLAZA",
      "LEXINGTON AVENUE 59 STREET",
      "5 AVENUE 59 STREET",
      "57 STREET 7 AVENUE",
      "49 STREET",
      "TIMES SQUARE 42 STREET",
      "34 STREET HERALD SQUARE",
      "28 STREET",
      "23 STREET",
      "14 STREET UNION SQUARE",
      "8 STREET NYU",
      "PRINCE STREET",
      "CANAL STREET",
      "CITY HALL",
      "CORTLANDT STREET",
      "RECTOR STREET",
      "WHITEHALL STREET SOUTH FERRY"
    };
    
    
    //z train stops
    vector<string> zTrainStops = {
      "JAMAICA CENTER PARSONS BOULEVARD ARCHER AVENUE",
      "SUTPHIN BOULEVARD ARCHER AVENUE JFK AIRPORT",
      "121 STREET",
      "104 STREET",
      "WOODHAVEN BOULEVARD",
      "75 STREET ELDERTS LANE",
      "CRESCENT STREET",
      "NORWOOD AVENUE",
      "VAN SICLEN AVENUE",
      "ALABAMA AVENUE",
      "BROADWAY JUNCTION",
      "CHAUNCEY STREET",
      "GATES AVENUE",
      "MYRTLE AVENUE",
      "MARCY AVENUE",
      "DELANCEY STREET ESSEX STREET",
      "BOWERY",
      "CANAL STREET",
      "CHAMBERS STREET",
      "FULTON STREET",
      "BROAD STREET"
    };

    // variables 
    string start, end, transferStop; 
    vector<Train> startingStationTrains; 
    vector<Train> endingStationTrains;
    vector<Train> transferStationTrains; 

    // creating all trains
    Train 
        oneTrain("1", oneTrainStops), 
        twoTrain("2", twoTrainStops), 
        threeTrain("3", threeTrainStops), 
        fourTrain("4", fourTrainStops),
        fiveTrain("5", fiveTrainStops), 
        sixTrain("6", sixTrainStops),
        sevenTrain("7", sevenTrainStops),
        aTrain("A", aTrainStops),
        bTrain("B", bTrainStops),
        cTrain("C", cTrainStops), 
        dTrain("D", dTrainStops),
        eTrain("E", eTrainStops),
        fTrain("F", fTrainStops),
        gTrain("G", gTrainStops),
        jTrain("J", jTrainStops),
        lTrain("L", lTrainStops),
        mTrain("M", mTrainStops),
        nTrain("N", nTrainStops),
        qTrain("Q", qTrainStops),
        rTrain("R", rTrainStops),
        msTrain("S", msTrainStops),
        bsTrain("S", msTrainStops),
        qsTrain("S", qsTrainStops),
        wTrain("W", wTrainStops),
        zTrain("Z", zTrainStops);

    //creating list of all trains    
    vector<Train> allTrains = {
        oneTrain,twoTrain,threeTrain,fourTrain,fiveTrain,sixTrain, 
        sevenTrain, aTrain, bTrain, cTrain, dTrain, eTrain, fTrain,
        gTrain, jTrain, lTrain, mTrain, nTrain, qTrain, rTrain,msTrain, 
        bsTrain, qsTrain, wTrain, zTrain
    }; 

    // program asks user for starting and ending stations
    cout<< "Where are you starting from?  ";     
    getline(cin, start);
    cout<<endl; 
    cout<< "Where would you like to go?  ";
    getline(cin, end);
    cout<<endl; 
    cout<< "Calculating route from " << start << " to " << end << endl; 
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    //group trains that pass through the starting and ending stops
    MakeTrainList (start, allTrains, startingStationTrains);
    MakeTrainList (end, allTrains, endingStationTrains);
    
    
    //showing route with 0 transfers
    cout<< "* Route with no transfers *"<<endl;
    DirectRoute (startingStationTrains, endingStationTrains);
    cout<< " from " << start << " to " << end << endl; 
    cout<<endl; 
    cout<<endl; 

    //showing route with transfer
    cout<< "* Route with transfers *" <<endl;
    
    //finds stations that can serve as a transfer station
    FindPossibleTransferStops (startingStationTrains, endingStationTrains, transferStop);
    
    //makes a list of possible transfer stations
    MakeTrainList (transferStop, allTrains, transferStationTrains);
    
    //calculates route from start to transfer station
    DirectRoute (startingStationTrains, transferStationTrains); 
    cout<< " from " << start << " to " << transferStop << " then "; 
    
    //calcualtes route from transfer station to destination
    DirectRoute (transferStationTrains, endingStationTrains); 
    cout<< " from " << transferStop << " to " << end << endl; 
    
    
return 0;
}

//cretes a list of all trains that go to a given stop
void MakeTrainList (string stop, vector<Train>& allTrains, vector<Train> &trainList){
    
    for (int i=0; i<allTrains.size(); i++){
    
        for (int j=0; j<allTrains.at(i).stops.size(); j++){
            
            if (allTrains.at(i).stops.at(j) == stop){
                
                trainList.push_back(allTrains.at(i)); 
            }   
        }
    }
};
    
//finds which trains can take you from stop A to stop B without transfering   
void DirectRoute (vector<Train>& startingStationTrains, vector<Train>& endingStationTrains){   
    vector<Train> matchingTrains; 
    bool routeFound = false; 

    for (int i=0; i<endingStationTrains.size(); i++){
        
        for (int j=0; j<startingStationTrains.size(); j++){
            
            if ( startingStationTrains.at(j).name == endingStationTrains.at(i).name){
                
                    matchingTrains.push_back(startingStationTrains.at(j));
                    routeFound = true; 
            }
        }
    }
        
    if (routeFound){
        
        cout<<"Take the ";
        for (int i=0; i<matchingTrains.size(); i++){
            
            if(i==0 && matchingTrains.size() == 1){
                
                cout<<matchingTrains.at(i).name<<" train";
            }
            else if (i < matchingTrains.size()){
                
                cout<<matchingTrains.at(i).name<<" train, ";
            }
            else{
                
                cout<<"or "<<matchingTrains.at(i).name<<" train"; 
            }
        }
    }
    else {
        cout << "No transferless route found!" <<endl;
    }
};

//find possible transfer stops and adds them to a vector
void FindPossibleTransferStops (vector<Train>& startingStationTrains, vector<Train>& endingStationTrains, string &transferStop){
    
    bool found = false;  
    
    for (int i=0; i<startingStationTrains.size() && !found; i++){
            
        for (int j=0; j<startingStationTrains.at(i).stops.size() && !found; j++){
            
            for (int x=0; x<endingStationTrains.size() && !found; x++){
                
                for (int y=0; y<endingStationTrains.at(x).stops.size() && !found; y++){
                    
                    if (startingStationTrains.at(i).stops.at(j) == endingStationTrains.at(x).stops.at(y)){
                        
                        transferStop = startingStationTrains.at(i).stops.at(j);
                            found = true; 
                    }
                }
            }
        }
    }
};
