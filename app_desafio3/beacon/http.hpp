#ifndef _INCL_HTTP_CLASS_
#define _INCL_HTTP_CLASS_

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;

class HTTP {
	public:
		int getData(const char* host, const char* port);
		int sendData(const char* host, const char* port,const char* contentType, const char* data);
};

#endif
