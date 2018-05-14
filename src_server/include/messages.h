/*
** EPITECH PROJECT, 2018
** MyIRC - Server
** File description:
** Messages
*/

#ifndef MESSAGES_H_
	#define MESSAGES_H_

	#define REPL_001 ("001 Welcome to the Internet Relay Network %s!%s@<host>")
	#define REPL_002 ("002 Your host is <servername>, running version <ver>")
	#define REPL_003 ("003 This server was created <date>")
	#define REPL_004 ("004 <servername> <version> <available user modes> <available channel modes>")
	#define REPL_005 ("005 Try server <server name>, port <port number>")
	#define REPL_200 ("200 Link <version & debug level> <destination> <next server> V<protocol version> <link uptime in seconds> <backstream sendq> <upstream sendq>")
	#define REPL_201 ("201 Try. <class> <server>")
	#define REPL_202 ("202 H.S. <class> <server>")
	#define REPL_203 ("203 ???? <class> [<client IP address in dot form>]")
	#define REPL_204 ("204 Oper <class> %s")
	#define REPL_205 ("205 User <class> %s")
	#define REPL_206 ("206 Serv <class> <int>S <int>C <server> <nick!user|*!*>@<host|server> V<protocol version>")
	#define REPL_207 ("207 Service <class> <name> <type> <active type>")
	#define REPL_208 ("208 <newtype> 0 <client name>")
	#define REPL_209 ("209 Class <class> <count>")
	#define REPL_211 ("211 <linkname> <sendq> <sent messages> <sent Kbytes> <received messages> <received Kbytes> <time open>")
	#define REPL_212 ("212 %s <count> <byte count> <remote count>")
	#define REPL_219 ("219 <stats letter> :End of STATS report")
	#define REPL_221 ("221 <user mode string>")
	#define REPL_234 ("234 <name> <server> <mask> <type> <hopcount> <info>")
	#define REPL_235 ("235 <mask> <type> :End of service listing")
	#define REPL_242 ("242 :Server Up %d days %d:%02d:%02d")
	#define REPL_243 ("243 O <hostmask> * <name>")
	#define REPL_251 ("251 :There are <integer> users and <integer> services on <integer> servers")
	#define REPL_252 ("252 <integer> :operator(s) online")
	#define REPL_253 ("253 <integer> :unknown connection(s)")
	#define REPL_254 ("254 <integer> :channels formed")
	#define REPL_255 ("255 :I have <integer> clients and <integer> servers")
	#define REPL_256 ("256 <server> :Administrative info")
	#define REPL_257 ("257 :<admin info>")
	#define REPL_258 ("258 :<admin info>")
	#define REPL_259 ("259 :<admin info>")
	#define REPL_261 ("261 File <logfile> <debug level>")
	#define REPL_262 ("262 <server name> <version & debug level> :End of TRACE")
	#define REPL_263 ("263 %s :Please wait a while and try again.")
	#define REPL_301 ("301 %s :<away message>")
	#define REPL_302 ("302 :*1<reply> *( " " <reply> )")
	#define REPL_303 ("303 :*1%s *( " " %s )")
	#define REPL_305 ("305 :You are no longer marked as being away")
	#define REPL_306 ("306 :You have been marked as being away")
	#define REPL_311 ("311 %s %s <host> * :<real name>")
	#define REPL_312 ("312 %s <server> :<server info>")
	#define REPL_313 ("313 %s :is an IRC operator")
	#define REPL_314 ("314 %s %s <host> * :<real name>")
	#define REPL_315 ("315 <name> :End of WHO list")
	#define REPL_317 ("317 %s <integer> :seconds idle")
	#define REPL_318 ("318 %s :End of WHOIS list")
	#define REPL_319 ("319 %s :*( ( "@" / "+" ) %s " " )")
	#define REPL_322 ("322 %s <# visible> :<topic>")
	#define REPL_323 ("323 :End of LIST")
	#define REPL_324 ("324 %s <mode> <mode params>")
	#define REPL_325 ("325 %s <nickname>")
	#define REPL_331 ("331 %s :No topic is set")
	#define REPL_332 ("332 %s :<topic>")
	#define REPL_341 ("341 %s %s")
	#define REPL_342 ("342 %s :Summoning user to IRC")
	#define REPL_346 ("346 %s <invitemask>")
	#define REPL_347 ("347 %s :End of channel invite list")
	#define REPL_348 ("348 %s <exceptionmask>")
	#define REPL_349 ("349 %s :End of channel exception list")
	#define REPL_351 ("351 <version>.<debuglevel> <server> :<comments>")
	#define REPL_352 ("352 %s %s <host> <server> %s ( "H" / "G" > ["*"] [ ( "@" / "+" ) ] :<hopcount> <real name>"))
	#define REPL_353 ("353 ( "=" / "*" / "@" ) %s :[ "@" / "+" ] %s *( " " [ "@" / "+" ] %s )")
	#define REPL_364 ("364 <mask> <server> :<hopcount> <server info>")
	#define REPL_365 ("365 <mask> :End of LINKS list")
	#define REPL_366 ("366 %s :End of NAMES list")
	#define REPL_367 ("367 %s <banmask>")
	#define REPL_368 ("368 %s :End of channel ban list")
	#define REPL_369 ("369 %s :End of WHOWAS")
	#define REPL_371 ("371 :<string>")
	#define REPL_372 ("372 :- <text>")
	#define REPL_374 ("374 :End of INFO list")
	#define REPL_375 ("375 :- <server> Message of the day - ")
	#define REPL_376 ("376 :End of MOTD command")
	#define REPL_381 ("381 :You are now an IRC operator")
	#define REPL_382 ("382 <config file> :Rehashing")
	#define REPL_383 ("383 You are service <servicename>")
	#define REPL_391 ("391 <server> :<string showing server's local time>")
	#define REPL_392 ("392 :UserID Terminal Host")
	#define REPL_393 ("393 :<username> <ttyline> <hostname>")
	#define REPL_394 ("394 :End of users")
	#define REPL_395 ("395 :Nobody logged in")
	#define REPL_401 ("401 <nickname> :No such nick/channel")
	#define REPL_402 ("402 <server name> :No such server")
	#define REPL_403 ("403 <channel name> :No such channel")
	#define REPL_404 ("404 <channel name> :Cannot send to channel")
	#define REPL_405 ("405 <channel name> :You have joined too many channels")
	#define REPL_406 ("406 <nickname> :There was no such nickname")
	#define REPL_407 ("407 <target> :<error code> recipients. <abort message>")
	#define REPL_408 ("408 <service name> :No such service")
	#define REPL_409 ("409 :No origin specified")
	#define REPL_411 ("411 :No recipient given (%s)")
	#define REPL_412 ("412 :No text to send")
	#define REPL_413 ("413 <mask> :No toplevel domain specified")
	#define REPL_414 ("414 <mask> :Wildcard in toplevel domain")
	#define REPL_415 ("415 <mask> :Bad Server/host mask")
	#define REPL_421 ("421 %s :Unknown command")
	#define REPL_422 ("422 :MOTD File is missing")
	#define REPL_423 ("423 <server> :No administrative info available")
	#define REPL_424 ("424 :File error doing <file op> on <file>")
	#define REPL_431 ("431 :No nickname given")
	#define REPL_432 ("432 %s :Erroneous nickname")
	#define REPL_433 ("433 %s :Nickname is already in use")
	#define REPL_436 ("436 %s :Nickname collision KILL from %s@<host>")
	#define REPL_437 ("437 <nick/channel> :Nick/channel is temporarily unavailable")
	#define REPL_441 ("441 %s %s :They aren't on that channel")
	#define REPL_442 ("442 %s :You're not on that channel")
	#define REPL_443 ("443 %s %s :is already on channel")
	#define REPL_444 ("444 %s :User not logged in")
	#define REPL_445 ("445 :SUMMON has been disabled")
	#define REPL_446 ("446 :USERS has been disabled")
	#define REPL_451 ("451 :You have not registered")
	#define REPL_461 ("461 %s :Not enough parameters")
	#define REPL_462 ("462 :Unauthorized command (already registered)")
	#define REPL_463 ("463 :Your host isn't among the privileged")
	#define REPL_464 ("464 :Password incorrect")
	#define REPL_465 ("465 :You are banned from this server")
	#define REPL_467 ("467 %s :Channel key already set")
	#define REPL_471 ("471 %s :Cannot join channel (+l)")
	#define REPL_472 ("472 %c :is unknown mode char to me for %s")
	#define REPL_473 ("473 %s :Cannot join channel (+i)")
	#define REPL_474 ("474 %s :Cannot join channel (+b)")
	#define REPL_475 ("475 %s :Cannot join channel (+k)")
	#define REPL_476 ("476 %s :Bad Channel Mask")
	#define REPL_477 ("477 %s :Channel doesn't support modes")
	#define REPL_478 ("478 %s %c :Channel list is full")
	#define REPL_481 ("481 :Permission Denied- You're not an IRC operator")
	#define REPL_482 ("482 %s :You're not channel operator")
	#define REPL_483 ("483 :You can't kill a server!")
	#define REPL_484 ("484 :Your connection is restricted!")
	#define REPL_485 ("485 :You're not the original channel operator")
	#define REPL_491 ("491 :No O-lines for your host")
	#define REPL_501 ("501 :Unknown MODE flag")
	#define REPL_502 ("502 :Cannot change mode for other users")

#endif /* !MESSAGES_H_ */