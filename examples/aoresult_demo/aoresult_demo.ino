// aoresult_demo.ino - demo of the convert-result-to-string feature of the aoresult library
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
#include <aoresult.h>


/*
DESCRIPTION
This demo shows how to convert the result codes from the aoresult lib
to strings.

HARDWARE
The demo runs on the OSP32 board, no demo board needs to be attached.
In Arduino select board "ESP32S3 Dev Module".
Since this demo does not use any OSP related hardware, any ESP32[S3] will do.

OUTPUT
Welcome to aoresult_demo.ino
Lib version 0.4.4
  0 | ok               | Success (no error)
  1 | assert           | This should not happen (dynamically checked assert)
  7 | spi_noclock      | No clock signal detected for response telegram
 23 | dev_i2cnack      | I2C transaction completed with NACK
 24 | <illegal>        | Illegal error code aoresult_numresultcodes
 -1 | <unknown>        | Unknown error code for aoresult_t
999 | <unknown>        | Unknown error code for aoresult_t
*/


// Print raw result code, its short string and its long string
void show( aoresult_t result ) {
  Serial.printf("%3d | %-16s | %s\n", result, aoresult_to_str(result), aoresult_to_str(result,1) );
}


void setup() {
  Serial.begin(115200);
  Serial.printf("\n\nWelcome to aoresult_demo.ino\n");
  Serial.printf("Lib version %s\n", AORESULT_VERSION );

  show( aoresult_ok );
  show( aoresult_assert );
  show( aoresult_spi_noclock );
  show( aoresult_dev_i2cnack );

  show( aoresult_numresultcodes );
  show( (aoresult_t)-1 );
  show( (aoresult_t)999 );
}


void loop() {
}
