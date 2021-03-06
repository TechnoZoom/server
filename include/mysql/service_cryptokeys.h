#ifndef MYSQL_SERVICE_CRYPTOKEYS_INCLUDED
/* Copyright (c) 2015, MariaDB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

/**
  @file
  cryptokeys service

  Functions get cryptographical keys and IV from the cryptokey management plugin
*/

#ifdef __cplusplus
extern "C" {
#endif

extern struct cryptokeys_service_st {
  unsigned int (*get_latest_crypto_key_version_func)();
  unsigned int (*has_crypto_key_func)(unsigned int);
  unsigned int (*get_crypto_key_size_func)(unsigned int);
  int (*get_crypto_key_func)(unsigned int, unsigned char*, unsigned int);
  int (*get_crypto_iv_func)(unsigned int, unsigned char*, unsigned int);
} *cryptokeys_service;

#ifdef MYSQL_DYNAMIC_PLUGIN

#define get_latest_crypto_key_version() cryptokeys_service->get_latest_crypto_key_version_func()
#define has_crypto_key(V) cryptokeys_service->has_crypto_key_func(V)
#define get_crypto_key_size(V) cryptokeys_service->get_crypto_key_size_func(V)
#define get_crypto_key(V,K,S) cryptokeys_service->get_crypto_key_func((V), (K), (S))
#define get_crypto_iv(V, I, S) cryptokeys_service->get_crypto_iv_func((V), (I), (S))

#else

unsigned int get_latest_crypto_key_version();
unsigned int has_crypto_key(unsigned int version);
unsigned int get_crypto_key_size(unsigned int version);
int get_crypto_key(unsigned int version, unsigned char* key, unsigned int keybufsize);
int get_crypto_iv(unsigned int version, unsigned char* iv, unsigned int ivbufsize);

#endif

#ifdef __cplusplus
}
#endif

#define MYSQL_SERVICE_CRYPTOKEYS_INCLUDED
#endif

