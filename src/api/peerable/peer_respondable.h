

#ifndef PEER_RESPONDABLE_H
#define PEER_RESPONDABLE_H

#include "utilities/platform.h"
#include <cstring>

namespace ARK
{
namespace API
{
namespace Peer
{
namespace Respondable
{

/*************************************************
*	ARK::API::Peer::Respondable::Version
*
*	@param:	char version{32]
*	@param:	char build[32]
*	@methods:	printTo(Print& p)
*
*	@brief:	Model for Loader Status API Response
**************************************************/
struct Version :
		public Printable
{
	protected:
		char version_[32];
		char build_[32];

	public:
		/*************************************************
		*	Constructor
		**************************************************/
		Version(
				const char* const newVersion,
				const char* const newBuild
		);
		/*************************************************/

		/*************************************************
		*	Accessors
		**************************************************/
		const char* version() const noexcept { return version_; }
		const char* build() const noexcept { return build_; }
		/*************************************************/
		
		/*************************************************
		*
		**************************************************/
    virtual size_t printTo(Print& p) const;
		/*************************************************/

};
/*************************************************/

};
};
};
};

#endif
