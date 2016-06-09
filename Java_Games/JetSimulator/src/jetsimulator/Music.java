/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jetsimulator;


import java.applet.Applet;
import java.applet.AudioClip;

/**
 *
 * @author Dipu
 */
public class Music {
    public static final AudioClip BACK = Applet.newAudioClip(Music.class.getResource("/audio/BattleTheme.wav"));
    public static final AudioClip SHOT = Applet.newAudioClip(Music.class.getResource("/audio/Laser.wav"));
    
}
