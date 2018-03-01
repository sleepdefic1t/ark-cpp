

#ifndef network_h
#define network_h

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

namespace ARK
{
/*************************************************
*   ARK::NetworkType
**************************************************/
enum NetworkType { INVALID = -1, DEV = 0, MAIN = 1, CUSTOM = 2 };
/*************************************************/

/**************************************************************************************************/

/*************************************************
*   ARK::network_t
**************************************************/
struct network_t {
	public:
		char nethash[65];
		char token[5];
		char symbol[2];
		char explorer[40];
		int version;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*   ARK::Network
**************************************************/
struct Network :
		public network_t, Printable
{
	public:

		Network()
		{
			strncpy(nethash, "", sizeof(nethash) / sizeof(nethash[0]));
			strncpy(token, "", sizeof(token) / sizeof(token[0]));
			strncpy(symbol, "", sizeof(symbol) / sizeof(symbol[0]));
			strncpy(explorer, "", sizeof(explorer) / sizeof(explorer[0]));
			version = 0;
		};

		Network(
			const char* const newNethash,
			const char* const newToken,
			const char* const newSymbol,
			const char* const newExplorer,
			int newVersion
		) {
			strncpy(nethash, newNethash, sizeof(nethash) / sizeof(nethash[0]));
			strncpy(token, newToken, sizeof(token) / sizeof(token[0]));
			strncpy(symbol, newSymbol, sizeof(symbol) / sizeof(symbol[0]));
			strncpy(explorer, newExplorer, sizeof(explorer) / sizeof(explorer[0]));
			version = newVersion;
		};

		/*************************************************
		*   ARK::Network::Network::operator==
		*
		*   @brief:
		*     Comparison of two Network Models for equality.
		**************************************************/
		bool operator==(const Network& rhs) const {
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
		*   ARK::Network::Network::operator!=
		*
		*   @brief:
		*     Comparison of two Network Models for inequality.
		**************************************************/
		bool operator!=(const Network& rhs) const { return !(*this == rhs); };
		/*************************************************/


		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
			
			size += p.print("\nnethash: ");
			size += p.print(this->nethash);

			size += p.print("\ntoken: ");
			size += p.print(this->token);

			size += p.print("\nsymbol: ");
			size += p.print(this->symbol);

			size += p.print("\nexplorer: ");
			size += p.print(this->explorer);

			size += p.print("\nversion: ");
			size += p.print(this->version);

			return size;
		}
			
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
/*************************************************/

#endif
