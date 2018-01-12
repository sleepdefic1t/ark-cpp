

#ifndef account_h
#define account_h

namespace ARK {

  struct Account {
    public:
      String address;
      String unconfirmedBalance;
      String balance;
      String publicKey;
      int unconfirmedSignature;
      int secondSignature;
      String secondPublicKey;
      String multisignatures;
      String u_multisignatures;

      Account();
      Account(String, String, String, String, int, int, String, String, String);

      String description();

  };

};


ARK::Account::Account() {
  address = "";
  unconfirmedBalance = "";
  balance = "";
  publicKey = "";
  unconfirmedSignature = 0;
  secondSignature = 0;
  secondPublicKey = "";
  multisignatures = "";
  u_multisignatures = "";
}
#include "address.h"

ARK::Account::Account(
  String _address,
  String _unconfirmedBalance,
  String _balance,
  String _publicKey,
  int _unconfirmedSignature,
  int _secondSignature,
  String _secondPublicKey,
  String _multisignatures,
  String _u_multisignatures) :
    address(_address),
    unconfirmedBalance(_unconfirmedBalance),
    balance(_balance),
    publicKey(_publicKey),
    unconfirmedSignature(_unconfirmedSignature),
    secondSignature(_secondSignature),
    secondPublicKey(_secondPublicKey),
    multisignatures(_multisignatures),
    u_multisignatures(_u_multisignatures) {}


String ARK::Account::Account::description() {
  String resp;
  resp += "address: ";
    resp += this->address;
    resp += "\n";
  resp += "unconfirmedBalance: ";
    resp += this->unconfirmedBalance;
    resp += "\n";
  resp += "balance: ";
    resp += this->balance;
    resp += "\n";
  resp += "publicKey: ";
    resp += this->publicKey;
    resp += "\n";
  resp += "unconfirmedSignature: ";
    resp += this->unconfirmedSignature;
    resp += "\n";
  resp += "secondSignature: ";
    resp += this->secondSignature;
    resp += "\n";
  resp += "secondPublicKey: ";
    resp += this->secondPublicKey;
    resp += "\n";
  resp += "multisignatures: ";
    resp += this->multisignatures;
    resp += "\n";
  resp += "u_multisignatures: ";
    resp += this->u_multisignatures;
    resp += "\n";
  return resp;
};

#endif
