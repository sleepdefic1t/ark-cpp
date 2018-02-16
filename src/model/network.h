

#ifndef network_h
#define network_h


namespace ARK
{

	/*************************************************
	*   ARK::NetworkType
	**************************************************/
  enum NetworkType { INVALID = -1, DEV = 0, MAIN = 1, CUSTOM = 2 };
	/*************************************************/

/********************************************************************************
*
* Network: 
*  	578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23
*		DARK
*		DѦ
*		https://dexplorer.ark.io/
*		30
*
********************************************************************************/


	/*************************************************
	*   ARK::Network
	**************************************************/
	struct Network {
		public:
			const char* nethash;
			const char* token;
			const char* symbol;
			const char* explorer;
			int version;

			bool operator==(const Network& rhs) const;
			bool operator!=(const Network& rhs) const;

			void printTo(HardwareSerial &serial);

	};
	/*************************************************/


	/**************************************************************************************************/


	/*************************************************
	*	ARK::Network_ADV
	**************************************************/
  namespace Network_ADV {
    struct bip32_t {
      long pub;         // base58 will have a prefix 'apub'
      long priv;        // base58Priv will have a prefix 'apriv'
    };
    struct network_t {
      const char* messagePrefix;
      bip32_t bip32;
      long pubKeyHash;  // Addresses will begin with 'A'
      long wif;         // Network prefix for wif generation
    };
  };
	/*************************************************/

};


/*************************************************
*	ARK::Network
*
*   @operator:	ARK::Network::Network::operator==
*
*   @description:
*     Comparison of two Network Models for equality.
*
**************************************************/
bool ARK::Network::Network::operator==(const Network& rhs) const {
  return (
		strcmp(this->nethash, rhs.nethash) == 0
		&& strcmp(this->token, rhs.token) == 0
		&& strcmp(this->symbol, rhs.symbol) == 0
		&& strcmp(this->explorer, rhs.explorer) == 0
		&& this->version == rhs.version
	);
};
/*************************************************/


/*************************************************
*	ARK::Network
*
*   @operator:	ARK::Network::Network::operator!=
*
*   @description:
*     Comparison of two Network Models for inequality.
*
**************************************************/
bool ARK::Network::Network::operator!=(const Network& rhs) const { return !(*this == rhs); };
/*************************************************/


/*************************************************
*	ARK::Network
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints Network Model information to Serial
*
**************************************************/
void ARK::Network::printTo(HardwareSerial &serial)
{
	serial.print("\nnethash: ");
	serial.print(this->nethash);
	serial.print("\ntoken: ");
	serial.print(this->token);
	serial.print("\nsymbol: ");
	serial.print(this->symbol);
	serial.print("\nexplorer: ");
	serial.print(this->explorer);
	serial.print("\nversion: ");
  serial.print(this->version);
  serial.print("\n");
  serial.flush();
};
/*************************************************/


#endif
