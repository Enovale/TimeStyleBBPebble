#include <pebble.h>
#include "languages.h"

/* day names in many different languages! */
char dayNames[22][7][8] = {
	{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"},
	{"DIM", "LUN", "MAR", "MER", "JEU", "VEN", "SAM"},
	{"SO",  "MO",  "DI",  "MI",  "DO",  "FR",  "SA"},
	{"DOM", "LUN", "MAR", "MIÉ", "JUE", "VIE", "SÁB"},
	{"DOM", "LUN", "MAR", "MER", "GIO", "VEN", "SAB"},
	{"ZO",  "MA",  "DI",  "WO",  "DO",  "VR",  "ZA"},
	{"PAZ", "PTS", "SAL", "ÇAR", "PER", "CUM", "CTS"},
	{"NE",  "PO",  "ÚT",  "ST",  "ČT",  "PÁ",  "SO"},
	{"DOM", "SEG", "TER", "QUA", "QUI", "SEX", "SÁB"},
	{"ΚΥΡ", "ΔΕΥ", "ΤΡΙ", "ΤΕΤ", "ΠΕΜ", "ΠΑΡ", "ΣΑΒ"},
	{"SÖN", "MÅN", "TIS", "ONS", "TOR", "FRE", "LÖR"},
	{"NDZ", "PON", "WTO", "ŚRO", "CZW", "PIĄ", "SOB"},
	{"NE", "PO", "UT", "ST", "ŠT", "PI", "SO"},
	{"CN", "T2", "T3", "T4", "T5", "T6", "T7"},
	{"DUM", "LUN", "MAR", "MIE", "JOI", "VIN", "SÂM"},
	{"DG", "DL", "DT", "DC", "DJ", "DV", "DS"},
	{"SØN", "MAN", "TIR", "ONS", "TOR", "FRE", "LØR"},
	{"ВС", "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ"},
	{"P", "E", "T", "K", "N", "R", "L"},
	{"IG", "AL", "AR", "AZ", "OG", "OL", "LR"},
	{"SU", "MA", "TI", "KE", "TO", "PE", "LA"},
	{"SØN", "MAN", "TIR", "ONS", "TOR", "FRE", "LØR"}
};

/* month names in many different languages! */
char monthNames[22][12][8] = {
	{"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"},
	{"JAN", "FÉV", "MAR", "AVR", "MAI", "JUI", "JUL", "AOÛ", "SEP", "OCT", "NOV", "DÉC"},
	{"JAN", "FEB", "MÄR", "APR", "MAI", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DEZ"},
	{"ENE", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DIC"},
	{"GEN", "FEB", "MAR", "APR", "MAG", "GIU", "LUG", "AGO", "SET", "OTT", "NOV", "DIC"},
	{"JAN", "FEB", "MRT", "APR", "MEI", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DEC"},
	{"OCA", "ŞUB", "MAR", "NİS", "MAY", "HAZ", "TEM", "AĞU", "EYL", "EKİ", "KAS", "ARA"},
	{"LED", "ÚNO", "BŘE", "DUB", "KVĚ", "ČRV", "ČVC", "SRP", "ZÁŘ", "ŘÍJ", "LIS", "PRO"},
	{"JAN", "FEV", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"},
	{"ΙΑΝ", "ΦΕΒ", "ΜΑΡ", "ΑΠΡ", "ΜΑΪ", "ΙΟΝ", "ΙΟΛ", "ΑΥΓ", "ΣΕΠ", "ΟΚΤ", "ΝΟΕ", "ΔΕΚ"},
	{"JAN", "FEB", "MAR", "APR", "MAJ", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DEC"},
	{"STY", "LUT", "MAR", "KWI", "MAJ", "CZE", "LIP", "SIE", "WRZ", "PAŹ", "LIS", "GRU"},
	{"JAN", "FEB", "MAR", "APR", "MÁJ", "JÚN", "JÚL", "AUG", "SEP", "OKT", "NOV", "DEC"},
	{"Th1", "Th2", "Th3", "Th4", "Th5", "Th6", "Th7", "Th8", "Th9", "T10", "T11", "T12"},
	{"IAN", "FEB", "MAR", "APR", "MAI", "IUN", "IUL", "AUG", "SEP", "OCT", "NOI", "DEC"},
	{"GEN", "FEB", "MAR", "ABR", "MAI", "JUN", "JUL", "AGO", "SET", "OCT", "NOV", "DES"},
	{"JAN", "FEB", "MAR", "APR", "MAI", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DES"},
	{"ЯНВ", "ФЕВ", "МАР", "АПР", "МАЙ", "ИЮН", "ИЮЛ", "АВГ", "СЕН", "ОКТ", "НОЯ", "ДЕК"},
	{"JAN", "VEB", "MÄR", "APR", "MAI", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DET"},
	{"URT", "OTS", "MAR", "API", "MAI", "EKA", "UZT", "ABU", "IRA", "URR", "AZA", "ABE"},
	{"TAM", "HEL", "MAA", "HUH", "TOU", "KES", "HEI", "ELO", "SYY", "LOK", "MAR", "JOU"},
	{"JAN", "FEB", "MAR", "APR", "MAJ", "JUN", "JUL", "AUG", "SEP", "OKT", "NOV", "DEC"}
};

// all of these are taken from:
// http://www.unicode.org/cldr/charts/28/by_type/date_&_time.fields.html#521165cf49647551
char wordForWeek[22][12] = {
	"Wk",
	"Sem",
	"W",
	"Sem",
	"Sett",
	"Wk",
	"Hf",
	"Týd",
	"Sem",
	"εβδ",
	"V",
	"Tydz"
	"Týž",
	"Tuần",
	"Săpt",
	"Setm",
	"Uke",
	"нед",
	"Näd",
	"Ast",
	"Vk",
	"Uge"
};
