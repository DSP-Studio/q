/*=============================================================================
   Copyright (c) 2014-2018 Joel de Guzman. All rights reserved.

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(CYCFI_Q_AUDIO_FILE_HPP_DECEMBER_1_2018)
#define CYCFI_Q_AUDIO_FILE_HPP_DECEMBER_1_2018

#include <vector>

namespace cycfi { namespace q
{
   ////////////////////////////////////////////////////////////////////////////
   class audio_device
   {
   public:

      enum io_dir { input, output };
      using device_list = std::vector<audio_device>;

      static device_list         list();
      uint32_t                   id() const;
      std::string                name() const;
      std::size_t                num_channels() const;
      io_dir                     direction() const;

   private:

      struct impl;
      audio_device(impl const& impl)
       : _impl(impl)
      {}

      impl const&                _impl;
   };
}}

#endif