# ExpLoRer_Crypto
ExpLoRer Crypto Test

This example locks both the ATECC508a configuration and data zones. This is required for most of the functionality tested. These processes however, are irreversible. Once locked the configuration zone cannot be modified and the settings for the invidual slots cannot be changed. 

Disclaimer (from the included MIT License):

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Libraries used:
  * CryptoAuthLib (modified): https://github.com/LieBtrau/CryptoAuthLib-arduino
  * AES Library: tiny-AES-c: https://github.com/kokke/tiny-AES-c
  * PKCS7: tiny-AES-c: https://github.com/triangulum-com-au/tiny-AES128-C 
