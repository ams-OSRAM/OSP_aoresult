// aoresult_assert.ino - demo of the assert feature of the aoresult library
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
This demo shows how to use the assert feature of the aoresult library.
Patch the definition of `AORESULT_ASSERT` if a debugger is attached.

HARDWARE
The demo runs on the OSP32 board, no demo board needs to be attached.
In Arduino select board "ESP32S3 Dev Module".
Since this demo does not use any OSP related hardware, any ESP32[S3] will do.

OUTPUT
Welcome to aoresult_assert.ino
Lib version 0.4.0
count 0
count 1
count 2
count 3
count 4
ASSERT( count < 5 ) in aoresult_assert.ino line 59
*/


int count;
void setup() {
  Serial.begin(115200);
  Serial.printf("\n\nWelcome to aoresult_assert.ino\n");
  Serial.printf("Lib version %s\n", AORESULT_VERSION );

  count=0;
}

void loop() {
  delay(2000);
  Serial.printf("count %d\n",count);
  count += 1;
  AORESULT_ASSERT( count < 5 );
}
