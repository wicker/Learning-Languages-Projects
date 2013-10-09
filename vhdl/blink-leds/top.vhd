-- Blink LEDs
-- Jenner Hanni
-- First program for the Terasic DE0-Nano
-----------------------------------------

library ieee;
use ieee.numeric_std.all

-----------------------------------------

entity blink_led is
  port (
    clk : in  std_logic;
    led : out std_logic_vector(7 downto 0);
    btn : in  std_logic_vector(1 downto 0);
  );
end blink_led;

-----------------------------------------

architecture behavioral of blink_led is 
begin


end behavioral;

