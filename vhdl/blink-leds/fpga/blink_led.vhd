-- Blink LEDs
-- Jenner Hanni
-- First program for the Terasic DE0-Nano
-----------------------------------------

library ieee;
use ieee.numeric_std.all;
use ieee.std_logic_1164.all;

-----------------------------------------

entity blink_led is
  port (
    clock_50  : in  std_logic;
    key       : in  std_logic_vector(1 downto 0);
    led       : out std_logic_vector(7 downto 0)
  );
end entity;

-----------------------------------------

architecture behavioral of blink_led is 
begin

  process (clock_50) begin

    if rising_edge(clock_50) then

      case key is 
        when "11" => led <= "00011000";
        when "01" => led <= "00001111";
        when "10" => led <= "11110000";
        when "00" => led <= "11111111";
      end case;

    end if;

  end process;

end behavioral;

