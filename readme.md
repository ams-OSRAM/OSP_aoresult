# OSP ResultCodes aoresult

Library "OSP ResultCodes aoresult", usually abbreviated to "aoresult",
is one of the **aolibs**; short for Arduino OSP libraries from ams-OSRAM.
This suite implements support for chips that use the Open System Protocol, 
like the AS1163 ("SAID") or the OSIRE E3731i ("RGBi").
The landing page for the _aolibs_ is on 
[GitHub](https://github.com/ams-OSRAM/OSP_aotop).


## Introduction

Library _aoresult_ is at the base of the dependency graph.
It contains (defines) a list of all error codes that
may occur in any of the _aolibs_.
As a result, library _aoresult_ is relatively empty.

![aoresult in context](extras/aolibs-aoresult.drawio.png)

The error codes could have been integrated in the next library 
in the hierarchy (_aospi_), and _aoresult_ would be superfluous. 
However, _aospi_ likely needs variants (supporting other MCUs, 
1-wire SPI, dropping mux support) so splitting off the error codes 
in a separate library _aoresult_ makes sense.


## Examples

This library comes with the following examples.
You can find them in the Arduino IDE via 
[File > Examples > OSP ResultCodes aoresult > ...](examples):

- **aoresult_demo** ([source](examples/aoresult_demo))  
  This demo shows how to convert the result codes from the aoresult lib
  to strings.

- **aoresult_assert** ([source](examples/aoresult_assert))  
  This demo shows how to use the assert feature of the aoresult library.
  Patch the definition of `AORESULT_ASSERT` if a debugger is attached.


## API

The header [aoresult.h](src/aoresult.h) contains the API of this library.
The header contains little documentation; for that see the
[aoresult.cpp](src/aoresult.cpp) source file. 

Here is a quick overview:

- `aoresult_t` the global list of error codes in the _aolibs_ (enumeration data type).

- `aoresult_to_str(result)` converts an error code to a (short) string or a (longer) description.

- `AORESULT_ASSERT(cond)` Checks if `cond` holds, if not, prints error to `Serial`, and stops.
   Uses helper function `aoresult_shorten(filename)`.

- Finally, there is the macro `AORESULT_VERSION`, which identifies the version of the library.


## Version history _aoresult_

- **2025 September 16, 0.5.0**
  - Added error `aoresult_dev_i2cmode` and `aoresult_osp_argsize` to better support I2C in modes 8 and 12.
  - Added link to examples.

- **2025 April 22, 0.4.6**
  - Made `aoresult.h` self contained: added `#include <Arduino.h>` for `Serial` in `AORESULT_ASSERT()`.

- **2024 November 29, 0.4.5**
  - Added error `aoresult_osp_nosr` for missing acknowledge.
  - Small updates in `aoresult_demo.ino`.
  - Fixed a typo.

- **2024 October 22, 0.4.4**
  - Removed hard coupling from names to integers; added `aoresult_numresultcodes`.
  - Added `aoresult_osp_psi`.

- **2024 October 8, 0.4.3**
  - Explained why separate library.

- **2024 October 7, 0.4.2**
  - Small textual updates of error messages
  - Moved domain from `github.com/ams-OSRAM-Group` to `github.com/ams-OSRAM`.
  
- **2024 September 5, 0.4.1**
  - Split example `aoresult_assert.ino` from `aoresult_demo.ino`.
  - API section in readme now shows parameter names.

- **2024 August 28, 0.4.0**
  - Added links in `readme.md` for all example sketches.
  - Added error `aoresult_sys_nodecfg`.

- **2024 August 9, 0.3.0**
  - Added error `aoresult_sys_wrongtopo`.

- **2024 August 5, 0.2.1**  
  - Corrected landing page link in readme.md from aotop to OSP_aotop.
  - Remove "oalib" from `sentence=` in `library.properties`.
  - Extra (indent) spaces in `aoresult_shorten()`.

- **2024 July 7, 0.2.0**  
  - Arduino name changed from `OSP Result codes - aoresult` to `OSP ResultCodes aoresult`.
  - Renamed dir `extra` to `extras`.

- **2024 July 3, 0.1.11**  
  - `license.txt`, `aoresult_demo.ino` line endings changed from LF to CR+LF.

- **2024 July 02, 0.1.10**  
  - Initial release candidate.

(end)
