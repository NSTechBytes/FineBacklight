-- ============================================================
--  NuraShade Lua Script
--  Copyright (c) 2025 NuraShade
--
--  Licensed under the Creative Commons Attribution-ShareAlike 3.0 Unported License.
--  You are free to:
--    • Share — copy and redistribute the material in any medium or format
--    • Adapt — remix, transform, and build upon the material
--      for any purpose, even commercially.
--
--  Under the following terms:
--    • Attribution — You must give appropriate credit, provide a link to the license,
--      and indicate if changes were made.
--    • ShareAlike — If you remix, transform, or build upon the material,
--      you must distribute your contributions under the same license as the original.
--
--  License Details: https://creativecommons.org/licenses/by-sa/3.0/
-- ============================================================
local move_x, move_y, anchor_x, anchor_y
local animation_steps, animation_displacement, animation_direction
local subject, t

local position_x_config = {
    L = function(sax, saw, pad) return sax + pad, 0, "0%" end,
    C = function(sax, saw, pad) return sax + saw / 2, 0.5, "50%" end,
    R = function(sax, saw, pad) return sax + saw - pad, 1, "100%" end
}

local position_y_config = {
    T = function(say, sah, pad) return say + pad, 0, "0%" end,
    C = function(say, sah, pad) return say + sah / 2, 0.5, "50%" end,
    B = function(say, sah, pad) return say + sah - pad, 1, "100%" end
}

local animation_offsets = {
    Left = function(progress, displacement) return (progress - 1) * displacement, 0 end,
    Right = function(progress, displacement) return (1 - progress) * displacement, 0 end,
    Top = function(progress, displacement) return 0, (progress - 1) * displacement end,
    Bottom = function(progress, displacement) return 0, (1 - progress) * displacement end
}

function Initialize()
    if SKIN:GetVariable('Use_As_Widget') == '0' then
        SKIN:Bang('[!Delay 100][!CommandMeasure Measure_Position_Animation_Timer "Execute 1"][!CommandMeasure Measure_Focus "#CURRENTCONFIG#"][!Draggable 0][!ZPos 1][!Log "Animating"]')
        
        -- Get position configuration
        local pos = SKIN:GetVariable('Position')
        local pos_x, pos_y = pos:sub(2, 2), pos:sub(1, 1)
        
        -- Get monitor dimensions
        local monitor_index = SKIN:GetVariable('Monitor_Index')
        local sax = tonumber(SKIN:GetVariable('WORKAREAX@' .. monitor_index))
        local say = tonumber(SKIN:GetVariable('WORKAREAY@' .. monitor_index))
        local saw = tonumber(SKIN:GetVariable('WORKAREAWIDTH@' .. monitor_index))
        local sah = tonumber(SKIN:GetVariable('WORKAREAHEIGHT@' .. monitor_index))
        
        -- Get padding
        local x_padding = tonumber(SKIN:GetVariable('X_Padding'))
        local y_padding = tonumber(SKIN:GetVariable('Y_Padding'))
        
        -- Calculate position using lookup tables
        local anchor_x_decimal, anchor_y_decimal
        move_x, anchor_x_decimal, anchor_x = position_x_config[pos_x](sax, saw, x_padding)
        move_y, anchor_y_decimal, anchor_y = position_y_config[pos_y](say, sah, y_padding)
        
        SKIN:Bang('!Draggable 0')
        SKIN:Bang('!SetWindowPosition ' .. move_x .. ' ' .. move_y .. ' ' .. anchor_x .. ' ' .. anchor_y)
        
        -- Handle animation
        if tonumber(SKIN:GetVariable('Animated')) == 1 then
            animation_steps = tonumber(SKIN:GetVariable('Animation_Steps'))
            animation_displacement = tonumber(SKIN:GetVariable('Animation_Displacement'))
            animation_direction = SKIN:GetVariable('Animation_Direction')
            
            dofile(SELF:GetOption("ScriptFile"):match("(.*[/\\])") .. "tween.lua")
            subject = { tween_node = 0 }
            t = tween.new(animation_steps, subject, {tween_node = 100}, SKIN:GetVariable('Ease_Type'))
        else
            SKIN:Bang('[!SetTransparency 255]')
        end
    else
        SKIN:Bang('[!Show][!SetTransparency 255][!Draggable 1][!ZPos 0][!SetAnchor 0 0]')
    end
end

function OnUnFocus()
    if SKIN:GetVariable('Use_As_Widget') == '0' then
        SKIN:Bang('[!CommandMeasure Measure_Position_Animation_Timer "Stop 1"][!CommandMeasure Measure_Position_Animation_Timer "Execute 2"][!Delay 200][!DeactivateConfig]')
    end
end

function TweenAnimation(dir)
    t:update(dir == 'in' and 1 or -1)
    
    -- Clamp tween node value
    local tween_value = subject.tween_node
    tween_value = tween_value > 100 and 100 or (tween_value < 0 and 0 or tween_value)
    
    -- Calculate animation offset
    local progress = tween_value / 100
    local offset_x, offset_y = animation_offsets[animation_direction](progress, animation_displacement)
    
    -- Build and execute bang command
    local bang = string.format(
        '[!SetWindowPosition %s %s %s %s][!SetTransparency %d]',
        move_x + offset_x, move_y + offset_y, anchor_x, anchor_y, progress * 255
    )
    
    SKIN:Bang(bang)
end
