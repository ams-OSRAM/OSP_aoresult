// aoresult.h - list of all error codes in any of the aolibs.
/*****************************************************************************
 * Copyright 2024,2025 by ams OSRAM AG                                       *
 * All rights are reserved.                                                  *
 *                                                                           *
 * IMPORTANT - PLEASE READ CAREFULLY BEFORE COPYING, INSTALLING OR USING     *
 * THE SOFTWARE.                                                             *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT         *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS         *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,     *
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT          *
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE     *
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.      *
 *****************************************************************************/
#ifndef _AORESULT_H_
#define _AORESULT_H_


#include <Arduino.h>         // Serial in AORESULT_ASSERT()


// Identifies lib version
#define AORESULT_VERSION "0.4.6"


// For detailed meaning, see aoresult_to_str()
typedef enum aoresult_e {
  // General errors
  aoresult_ok              , //  0
  aoresult_assert          , //  1
  aoresult_outargnull      , //  2
  aoresult_outofmem        , //  3
  aoresult_comparefail     , //  4
  aoresult_other           , //  5

  // Errors from aospi
  aoresult_spi_buf         , //  6
  aoresult_spi_noclock     , //  7
  aoresult_spi_length      , //  8

  // Errors for aoosp
  aoresult_osp_arg         , //  9
  aoresult_osp_addr        , // 10
  aoresult_osp_preamble    , // 11
  aoresult_osp_tid         , // 12
  aoresult_osp_size        , // 13
  aoresult_osp_psi         , // 14
  aoresult_osp_crc         , // 15
  aoresult_osp_nosr        , // 16

  // Errors on OSP system
  aoresult_sys_cabling     , // 17
  aoresult_sys_id          , // 18
  aoresult_sys_wrongtopo   , // 19
  aoresult_sys_nodecfg     , // 20

  // Errors for attached devices
  aoresult_dev_noi2cbridge , // 21
  aoresult_dev_noi2cdev    , // 22
  aoresult_dev_i2ctimeout  , // 23
  aoresult_dev_i2cnack     , // 24
  
  aoresult_numresultcodes    // 25 keep this as last
} aoresult_t;


// Converts an aoresult_t error code to a string.
const char * aoresult_to_str(aoresult_t result, int verbose=0);


// Converts file path to just the file base name (clips on last directory separator).
const char * aoresult_shorten( const char * file);


/*!
    @brief  Checks if `cond` holds, if not, prints error to Serial, and stops.
    @param  cond
            Condition to be checked for true-ness
    @note   If `cond` does not hold program stops.
    @note   If a debugger is connected, un-comment the break instruction.
*/
#define AORESULT_ASSERT(cond) \
  if( !(cond) ) { \
    Serial.printf("ASSERT( %s ) in %s line %d\n", #cond, aoresult_shorten(__FILE__), __LINE__ ); \
    /* asm("break.n 1"); */ while(1) /*wait*/ ; \
  }

#endif
