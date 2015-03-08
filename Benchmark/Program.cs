using System;
using System.Linq;
using LzmaNet;

namespace Benchmark
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			Random rand = new Random();
			byte[] randomBytes = Enumerable.Range(0, 1024 * 1024).Select(i => (byte)i).ToArray();

			byte[] randomBytes2 = new byte[randomBytes.Length * 2 + Lzma.PropertiesSize];
			int propertiesSize = Lzma.PropertiesSize;
			int bufferSize = randomBytes2.Length - propertiesSize;
			Lzma.Compress(randomBytes, 0, randomBytes.Length, randomBytes2, propertiesSize, ref bufferSize, randomBytes2, 0, ref propertiesSize, new LzmaProperties());

		}
	}
}
