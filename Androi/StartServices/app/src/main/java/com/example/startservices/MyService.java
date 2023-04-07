package com.example.startservices;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import androidx.annotation.Nullable;
import android.media.MediaPlayer;
import android.provider.Settings;

import com.google.android.material.color.utilities.PointProviderLab;

public abstract class MyService extends Service {
    private MediaPlayer player;

    public MyService(MediaPlayer player) {
        this.player = player;
    }
    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }
    @Override
    public void onDestroy(){
        player.stop();
    }
   public int onStartCommand(Intent intent, int flags, int startID) {
        player = MediaPlayer.create(this, Settings.System.DEFAULT_RINGTONE_URI);
        player .setLooping(true);
        player.start();
        return START_STICKY;
   }

}
