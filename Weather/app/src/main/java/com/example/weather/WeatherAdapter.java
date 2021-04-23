package com.example.weather;

import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class WeatherAdapter extends RecyclerView.Adapter<WeatherAdapter.ViewHolder>{
    private List<weatherSituation> mweatherlist;
    static class ViewHolder extends RecyclerView.ViewHolder{
     TextView weather_city;
     TextView weatherupdate_time;
     TextView weather_wea;
     TextView weather_tem;
     TextView weathertem_day;
     TextView weathertem_night;
     TextView weather_win;
     TextView weatherwin_speed;
     TextView weather_air;
     public ViewHolder(View view){
         super(view);
         weather_city=(TextView) view.findViewById(R.id.title_city);
         weatherupdate_time=(TextView)view.findViewById(R.id.title_update_time);
         weather_wea=(TextView)view.findViewById(R.id.weather_wea);
         weather_tem=(TextView)view.findViewById(R.id.weather_tem);
         weathertem_day=(TextView)view.findViewById(R.id.tem_day);
         weathertem_night=(TextView)view.findViewById(R.id.tem_night);
         weather_win=(TextView)view.findViewById(R.id.win);
         weatherwin_speed=(TextView)view.findViewById(R.id.win_speed);
         weather_air=(TextView)view.findViewById(R.id.air);
     }
    }
    public WeatherAdapter(List<weatherSituation> weatherlist)
    {
        mweatherlist=weatherlist;
    }
    @Override
    public ViewHolder onCreateViewHolder(ViewGroup parent,int viewType){
        View view= LayoutInflater.from(parent.getContext()).inflate(R.layout.weather_item,parent,false);
        ViewHolder holder=new ViewHolder(view);
        return holder;

    }
   @Override
    public void onBindViewHolder(ViewHolder holder,int position) {
       weatherSituation weather = mweatherlist.get(position);
           holder.weather_city.setText(weather.getCity());
           holder.weatherupdate_time.setText(weather.getUpdate_time());
           holder.weather_wea.setText(weather.getWea());
           holder.weather_tem.setText(weather.getTem());
           holder.weathertem_day.setText(weather.getTem_day());
           holder.weathertem_night.setText(weather.getTem_night());
           holder.weather_win.setText(weather.getWin());
           holder.weatherwin_speed.setText(weather.getWin_speed());
           holder.weather_air.setText(weather.getAir());

   }

    @Override
    public int getItemCount(){
        return mweatherlist.size();
   }
}
