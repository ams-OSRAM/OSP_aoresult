// aoresult.cpp - list of all error codes in any of the aolibs.
/*****************************************************************************
 * Copyright 2024 by ams OSRAM AG                                            *
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
#include <string.h>   // strrchr()
#include <aoresult.h> // own


/*!
    @brief  Converts an aoresult_t error code to a string.
    @param  result
            An error code (tag) from the global enum aoresult_t.
    @param  verbose
            When zero (default) returns a short string, basically
            the same as the name of the enum tag without the prefix.
            When non-zero returns a long string, giving a description
            of the error code.
    @return a constant string.
    @note   If the the error code is not part of aoresult_t, the function
            returns "<unknown>".
*/
const char * aoresult_to_str(aoresult_t result, int verbose) {
  switch( result ) {
    case aoresult_ok               : return verbose==0 ? "ok"              : "Success (no error)";
    case aoresult_assert           : return verbose==0 ? "assert"          : "This should not happen (dynamically checked assert)";
    case aoresult_outargnull       : return verbose==0 ? "outargnull"      : "An output argument is NULL";
    case aoresult_outofmem         : return verbose==0 ? "outofmem"        : "Out of memory (eg topo database)";
    case aoresult_comparefail      : return verbose==0 ? "comparefail"     : "Comparison (eg eeprom) between expected an actual failed";
    case aoresult_other            : return verbose==0 ? "other"           : "Other error - not further specified";
    
    case aoresult_spi_buf          : return verbose==0 ? "spi_buf"         : "Illegal buffer input parameter (null pointer, illegal size)";
    case aoresult_spi_noclock      : return verbose==0 ? "spi_noclock"     : "No clock signal detected for response telegram";
    case aoresult_spi_length       : return verbose==0 ? "spi_length"      : "Response telegram length differs from requested";

    case aoresult_osp_arg          : return verbose==0 ? "osp_arg"         : "An OSP telegram argument has an illegal value";
    case aoresult_osp_addr         : return verbose==0 ? "osp_addr"        : "The address for an OSP telegram is illegal";
    case aoresult_osp_preamble     : return verbose==0 ? "osp_preamble"    : "Preamble incorrect in response telegram";
    case aoresult_osp_tid          : return verbose==0 ? "osp_tid"         : "Unexpected telegram ID in response telegram";
    case aoresult_osp_size         : return verbose==0 ? "osp_size"        : "Unexpected size for response telegram";
    case aoresult_osp_crc          : return verbose==0 ? "osp_crc"         : "CRC mismatch in response telegram";
    
    case aoresult_sys_cabling      : return verbose==0 ? "sys_cabling"     : "Resetinit failed: cable (loop) or terminator (bidir) missing";
    case aoresult_sys_id           : return verbose==0 ? "sys_id"          : "Unexpected or unknown OSP node ID";
    case aoresult_sys_wrongtopo    : return verbose==0 ? "sys_wrongtopo"   : "Actual OSP chain topology deviates from expected";
    case aoresult_sys_nodecfg      : return verbose==0 ? "sys_nodecfg"     : "OSP node has unexpected config (star, sync, haptic, cluster, ...)";

    case aoresult_dev_noi2cbridge  : return verbose==0 ? "dev_noi2cbridge" : "Missing (OSP node with) I2C bridge";
    case aoresult_dev_noi2cdev     : return verbose==0 ? "dev_noi2cdev"    : "Missing specific I2C device (eg app needs EEPROM or I/O-Expander)";
    case aoresult_dev_i2ctimeout   : return verbose==0 ? "dev_i2ctimeout"  : "I2C transaction took too long to complete";
    case aoresult_dev_i2cnack      : return verbose==0 ? "dev_i2cnack"     : "I2C transaction completed with NACK";
  }
  // By not having a default in the switch, a good compiler gives a warning when a case/tag is forgotten.
  return verbose==0 ? "<unknown>"      : "Unknown error code for aoresult_t";
}


/*!
    @brief  Converts file path to just the file base name (clips on last directory separator).
    @param  file
            A string (typically filename) which is clipped at the last \ or /.
    @return (Pointer to) the file base name.
    @note   If there is no \ or / returns `file`.
*/
const char * aoresult_shorten( const char * file) {
  char * p;
  p= strrchr(file, '/');
  if( p!=0 ) return p+1;
  p= strrchr(file, '\\');
  if( p!=0 ) return p+1;
  return file; 
}

